﻿//Copyright © 2014 (´･@･)
//[License]GNU Affero General Public License, version 3
//[Contact]http://tacoika.blog87.fc2.com/
#pragma once
#include "PlaceData.h"
#include "../System/EnumType.h"
#include "../System/TDSystem.h"
#include "../System/Material.h"
#include <Multimedia/Directory.h>

namespace SDX_TD
{
    using namespace SDX;

    /**ステージの情報.*/
    struct StageData
    {
        //作者名は読み込まない
        std::string 名前;
        std::string 説明;
        int Wave間隔;

        struct Score
        {
            Score()
            {
                for (auto &it : スコア){ it = 0; }
                for (auto &it : 勝利){ it = -1; }
                for (auto &it : 完勝){ it = -1; }
            }

            EnumArray<long long, WitchType> スコア;
            EnumArray<int, WitchType> 勝利;
            EnumArray<int, WitchType> 完勝;
        };

        //全体の最高スコア
        //[isトライアル][isカップル]
        Score 成績[2][2];

        EnemyType 敵種類[MAX_WAVE];
        bool	  isBoss[MAX_WAVE];
        ChipType  地形[MAP_SIZE][MAP_SIZE];//地形種類
		int       地形画像[MAP_SIZE][MAP_SIZE];//地形画像

        Score& Getスコア()
        {
            return 成績[TDSystem::isスキル][TDSystem::isカップル];
        }

		long long Get最大スコア()
		{
			return std::max(
			{
				Getスコア().スコア[WitchType::ライナ],
				Getスコア().スコア[WitchType::ナツメ],
				Getスコア().スコア[WitchType::ルコウ],
				Getスコア().スコア[WitchType::ディアネラ],
				Getスコア().スコア[WitchType::ミナエ],
				Getスコア().スコア[WitchType::トレニア],
				Getスコア().スコア[WitchType::ロチエ],
				Getスコア().スコア[WitchType::バロゥ],
				Getスコア().スコア[WitchType::フィオナ],
				Getスコア().スコア[WitchType::ナズナ],
				Getスコア().スコア[WitchType::委員長],
				Getスコア().スコア[WitchType::ミルラ],
			});
		}

        //メインウィッチ種、トライアルorパワー
        std::vector<Place> 初期配置[(int)WitchType::COUNT][2];

        /*ミニマップを表示する.*/
        /* 基準には中央座標を入れる*/
        void DrawMinimap(const Point &基準座標 , bool isステージ名 = true)
        {
            if (名前 == "") { return; }

            Point dif = { -(MAP_SIZE-1) * CHIP_SIZE / 4 , -(MAP_SIZE-1) * CHIP_SIZE / 4};

            for (int x = 2; x < MAP_SIZE - 2; ++x)
            {
                for (int y = 2; y < MAP_SIZE - 2; ++y)
                {
                    MSystem::マップチップ[(int)地形[x][y]]->DrawRotate(基準座標 + Point(x * CHIP_SIZE / 2, y * CHIP_SIZE / 2) + dif, 0.5, 0);
                }
            }

            //ステージ名も表示
            if (isステージ名)
            {
                MFont::fontS[1].DrawRotate(基準座標 + Point(0, MAP_SIZE * CHIP_SIZE / 4 + 10 ),1,0,Color::White, 名前);
            }
        }

		long long Update(WitchType 種類, long long スコア , ResultType 結果)
		{
			long long exp = 0;

			//全体スコアの更新計算
			if (スコア > Get最大スコア())
			{
				exp += (スコア - Get最大スコア()) * 5;
			}
			//個別スコアの更新計算
			if (スコア > Getスコア().スコア[種類])
			{
				exp += スコア - Getスコア().スコア[種類];
				Getスコア().スコア[種類] = スコア;
			}

			switch (結果)
			{
			case ResultType::Perfect:
				Getスコア().完勝[種類] = std::max(Getスコア().完勝[種類], (int)TDSystem::難易度);
			case ResultType::Win:
				Getスコア().勝利[種類] = std::max(Getスコア().勝利[種類], (int)TDSystem::難易度);
				break;
			default:
				break;
			}

			return exp;
		}
    };

    std::map< std::string, StageData > StageDataS;//全部文字列で管理

    void LoadStageS()
    {
        //ディレクトリ内のファイルを列挙
        auto fileS = Directory::GetFileName("file/map");
        auto freeS = Directory::GetFileName("file/map/free");

        for (auto &it : freeS)
        {
            //tmxファイル以外は無視
            if (it.find(".tmx") == std::string::npos){ continue; }           
            fileS.push_back( std::string("free/") + it );
            StageType::Free.push_back( std::string("free/") + it);
        }

        //ソフト起動時のみ行う
        bool isMap = false;
        bool isEnemy = false;
        int line = 0;
        int chipEnemy;
        int chipMap;

        for (auto it : fileS)
        {
            //tmxファイル以外は無視
            if (it.find(".tmx") == std::string::npos){ continue; }

            File file( (std::string("file/map/") + it).c_str(), FileMode::Read, true);
            StageData& data = StageDataS[it];
            auto strS = file.GetLineS();

            for (auto &str : strS)
            {
                if (isMap || isEnemy)
                {
                    std::istringstream iss(str);
                    std::string buf;
                    int count = 0;

                    while (std::getline(iss, buf, ','))
                    {
                        if (line == -1){ break; }//data encoding="csv"を無視

                        if (isEnemy)
                        {
                            int num = (std::atoi(buf.c_str()) - chipEnemy);

                            data.敵種類[count + line * 10] = (EnemyType)(num % 20);
                            data.isBoss[count + line * 10] = (num >= 20);

                            if (count == 9){ break; }
                        }
                        else
                        {
                            data.地形[count][line] = (ChipType)(std::atoi(buf.c_str()) - chipMap);
                        }
                        ++count;
                    }
                    ++line;
                    if (isEnemy && line == 10){ isEnemy = false; }
                    if (isMap && line == 32){ isMap = false; }
                }
                else if (str.find("enemy") != std::string::npos && str.find("tileset") != std::string::npos)
                {
                    chipEnemy = std::atoi(GetTag(str, "firstgid=").c_str());
                }
                else if (str.find("mapchip") != std::string::npos && str.find("tileset") != std::string::npos)
                {
                    chipMap = std::atoi(GetTag(str, "firstgid=").c_str());
                }
                else if (str.find("Info") != std::string::npos)
                {
                    data.説明 = GetTag(str, "value=");
                }
                else if (str.find("Name") != std::string::npos)
                {
                    data.名前 = GetTag(str, "value=");
                }
                else if (str.find("WaveSpeed") != std::string::npos)
                {
                    data.Wave間隔 = std::atoi(GetTag(str, "value=").c_str());
                }
                else if (str.find("layer name=\"map\"") != std::string::npos)
                {
                    isMap = true;
                    line = -1;
                }
                else if (str.find("layer name=\"enemy\"") != std::string::npos)
                {
                    isEnemy = true;
                    line = -1;
                }
            }
        }

    }

	void CheckScore()
	{
		TDSystem::シングル総スコア.現在値 = 0;
		TDSystem::タッグ総スコア.現在値 = 0;
		TDSystem::クエスト銀星数.現在値 = 0;
		TDSystem::クエスト金星数.現在値 = 0;

		for (int a = 0;a < StageType::COUNT;++a)
		{
			for (int b = 0;b < (int)WitchType::COUNT;++b)
			{
				TDSystem::シングル総スコア.現在値 += StageDataS[StageType::Quest[a]].成績[true][false].スコア[WitchType(b)];
				TDSystem::シングル総スコア.現在値 += StageDataS[StageType::Quest[a]].成績[false][false].スコア[WitchType(b)];
				TDSystem::タッグ総スコア.現在値 += StageDataS[StageType::Quest[a]].成績[true][true].スコア[WitchType(b)];
				TDSystem::タッグ総スコア.現在値 += StageDataS[StageType::Quest[a]].成績[false][true].スコア[WitchType(b)];

				TDSystem::クエスト銀星数.現在値 += StageDataS[StageType::Quest[a]].成績[false][true].勝利[WitchType(b)] + 1;
				TDSystem::クエスト銀星数.現在値 += StageDataS[StageType::Quest[a]].成績[true][true].勝利[WitchType(b)] + 1;
				TDSystem::クエスト銀星数.現在値 += StageDataS[StageType::Quest[a]].成績[true][false].勝利[WitchType(b)] + 1;
				TDSystem::クエスト銀星数.現在値 += StageDataS[StageType::Quest[a]].成績[false][false].勝利[WitchType(b)] + 1;

				TDSystem::クエスト金星数.現在値 += StageDataS[StageType::Quest[a]].成績[false][true].完勝[WitchType(b)] + 1;
				TDSystem::クエスト金星数.現在値 += StageDataS[StageType::Quest[a]].成績[true][false].完勝[WitchType(b)] + 1;
				TDSystem::クエスト金星数.現在値 += StageDataS[StageType::Quest[a]].成績[false][false].完勝[WitchType(b)] + 1;
				TDSystem::クエスト金星数.現在値 += StageDataS[StageType::Quest[a]].成績[true][true].完勝[WitchType(b)] + 1;
			}
		}
	}
}