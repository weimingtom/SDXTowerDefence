﻿//Copyright © 2014 (´･@･)
//[License]GNU Affero General Public License, version 3
//[Contact]http://tacoika.blog87.fc2.com/
#pragma once
#include <SDXFramework.h>
#include "../System/EnumType.h"

namespace SDX_TD
{
    using namespace SDX;

    /**敵＆ウィッチの画像.*/
    namespace MUnit
    {
        EnumArray<ImagePack, UnitType> 味方;
        EnumArray<ImagePack, EnemyType> 敵;

        static void Load()
        {
            味方[UnitType::ライナ].Load("file/unit/witch/lina.png", 9, 3, 3);
            味方[UnitType::ナツメ].Load("file/unit/witch/natsume.png", 9, 3, 3);
            味方[UnitType::ルコウ].Load("file/unit/witch/rukou.png", 9, 3, 3);
            味方[UnitType::ディアネラ].Load("file/unit/witch/dianella.png", 9, 3, 3);
            味方[UnitType::ミナエ].Load("file/unit/witch/minae.png", 9, 3, 3);
            味方[UnitType::トレニア].Load("file/unit/witch/torenia.png", 9, 3, 3);
            味方[UnitType::ロチエ].Load("file/unit/witch/rochie.png", 9, 3, 3);
            味方[UnitType::バロゥ].Load("file/unit/witch/barrow.png", 9, 3, 3);
            味方[UnitType::フィオナ].Load("file/unit/witch/fiona.png", 9, 3, 3);
            味方[UnitType::ナズナ].Load("file/unit/witch/nazuna.png", 9, 3, 3);
            味方[UnitType::委員長].Load("file/unit/witch/chairwoman.png", 9, 3, 3);
            味方[UnitType::ミルラ].Load("file/unit/witch/myrra.png", 9, 3, 3);

            味方[UnitType::兵士].Load("file/unit/common/000.png", 9, 3, 3);
            味方[UnitType::踊り子].Load("file/unit/common/001.png", 9, 3, 3);
            味方[UnitType::狩人].Load("file/unit/common/002.png", 9, 3, 3);
            味方[UnitType::執事].Load("file/unit/common/003.png", 9, 3, 3);
            味方[UnitType::技師].Load("file/unit/common/004.png", 9, 3, 3);
            味方[UnitType::くノ一].Load("file/unit/common/005.png", 9, 3, 3);
            味方[UnitType::師範].Load("file/unit/common/006.png", 9, 3, 3);
            味方[UnitType::術士].Load("file/unit/common/007.png", 9, 3, 3);
            味方[UnitType::賢者].Load("file/unit/common/008.png", 9, 3, 3);
            味方[UnitType::武闘家].Load("file/unit/common/009.png", 9, 3, 3);
            味方[UnitType::忍者].Load("file/unit/common/010.png", 9, 3, 3);
            味方[UnitType::剣豪].Load("file/unit/common/011.png", 9, 3, 3);
            味方[UnitType::料理人].Load("file/unit/common/012.png", 9, 3, 3);
            味方[UnitType::勇者].Load("file/unit/common/013.png", 9, 3, 3);
            味方[UnitType::射手].Load("file/unit/common/014.png", 9, 3, 3);
            味方[UnitType::盗賊].Load("file/unit/common/015.png", 9, 3, 3);
            味方[UnitType::騎士].Load("file/unit/common/016.png", 9, 3, 3);
            味方[UnitType::司祭].Load("file/unit/common/017.png", 9, 3, 3);
            味方[UnitType::僧侶].Load("file/unit/common/018.png", 9, 3, 3);
            味方[UnitType::闘士].Load("file/unit/common/019.png", 9, 3, 3);
            味方[UnitType::斧士].Load("file/unit/common/020.png", 9, 3, 3);
            味方[UnitType::傭兵].Load("file/unit/common/021.png", 9, 3, 3);
            味方[UnitType::プリンス].Load("file/unit/common/022.png", 9, 3, 3);
            味方[UnitType::プリンセス].Load("file/unit/common/023.png", 9, 3, 3);
            味方[UnitType::剣士].Load("file/unit/common/024.png", 9, 3, 3);
            味方[UnitType::槍士].Load("file/unit/common/025.png", 9, 3, 3);
            味方[UnitType::給仕].Load("file/unit/common/026.png", 9, 3, 3);
            味方[UnitType::足軽].Load("file/unit/common/027.png", 9, 3, 3);
            味方[UnitType::将軍].Load("file/unit/common/028.png", 9, 3, 3);
            味方[UnitType::軍師].Load("file/unit/common/029.png", 9, 3, 3);

            敵[EnemyType::ゼリー].Load("file/enemy/000.png", 9, 3, 3);
            敵[EnemyType::ゴブリン].Load("file/enemy/001.png", 9, 3, 3);
            敵[EnemyType::ケットシー].Load("file/enemy/002.png", 9, 3, 3);
            敵[EnemyType::オーガ].Load("file/enemy/003.png", 9, 3, 3);
            敵[EnemyType::コボルド].Load("file/enemy/004.png", 9, 3, 3);
            敵[EnemyType::ゴーレム].Load("file/enemy/005.png", 9, 3, 3);
            敵[EnemyType::ケルベロス].Load("file/enemy/006.png", 9, 3, 3);
            敵[EnemyType::スケルトン].Load("file/enemy/007.png", 9, 3, 3);
            敵[EnemyType::シャーマン].Load("file/enemy/008.png", 9, 3, 3);
            敵[EnemyType::ゼリー王].Load("file/enemy/009.png", 9, 3, 3);
            敵[EnemyType::マーマン].Load("file/enemy/010.png", 9, 3, 3);
            敵[EnemyType::インプ].Load("file/enemy/011.png", 9, 3, 3);
            敵[EnemyType::トレント].Load("file/enemy/012.png", 9, 3, 3);
            敵[EnemyType::グリフィン].Load("file/enemy/013.png", 9, 3, 3);
            敵[EnemyType::ドラゴン].Load("file/enemy/014.png", 9, 3, 3);
        }
    }

    /**その他のアイコン.*/
    namespace MIcon
    {
        ImagePack ターゲット;
        EnumArray<Image, IconType> UI;
        EnumArray<Image, WitchType> 魔導具;
        EnumArray<Image, Element> 属性;

        static void Load()
        {
            ターゲット.Load("file/system/target.png", 3, 3, 1);

            UI[IconType::ライフ].Load("file/system/icon/000.png");
            UI[IconType::マナ].Load("file/system/icon/001.png");
            UI[IconType::レベル].Load("file/system/icon/002.png");
            UI[IconType::攻撃].Load("file/system/icon/003.png");
            UI[IconType::連射].Load("file/system/icon/004.png");
            UI[IconType::支援].Load("file/system/icon/005.png");
            UI[IconType::鈍足].Load("file/system/icon/006.png");
            UI[IconType::麻痺].Load("file/system/icon/007.png");
            UI[IconType::強化].Load("file/system/icon/008.png");
            UI[IconType::吹飛].Load("file/system/icon/009.png");
            UI[IconType::防壊].Load("file/system/icon/010.png");
            UI[IconType::速度].Load("file/system/icon/011.png");
            UI[IconType::回避].Load("file/system/icon/012.png");
            UI[IconType::防御].Load("file/system/icon/013.png");
            UI[IconType::回復].Load("file/system/icon/014.png");
			UI[IconType::銅メダル].Load("file/system/icon/015.png");
			UI[IconType::銀メダル].Load("file/system/icon/016.png");
			UI[IconType::金メダル].Load("file/system/icon/017.png");

            魔導具[WitchType::ライナ].Load("file/unit/artifact/000.png");
            魔導具[WitchType::ナツメ].Load("file/unit/artifact/001.png");
            魔導具[WitchType::ルコウ].Load("file/unit/artifact/002.png");
            魔導具[WitchType::ディアネラ].Load("file/unit/artifact/003.png");
            魔導具[WitchType::ミナエ].Load("file/unit/artifact/004.png");
            魔導具[WitchType::トレニア].Load("file/unit/artifact/005.png");
            魔導具[WitchType::ロチエ].Load("file/unit/artifact/006.png");
            魔導具[WitchType::バロゥ].Load("file/unit/artifact/007.png");
            魔導具[WitchType::フィオナ].Load("file/unit/artifact/008.png");
            魔導具[WitchType::ナズナ].Load("file/unit/artifact/009.png");
            魔導具[WitchType::委員長].Load("file/unit/artifact/010.png");
            魔導具[WitchType::ミルラ].Load("file/unit/artifact/011.png");

            属性[Element::炎].Load("file/unit/element/000.png");
            属性[Element::氷].Load("file/unit/element/001.png");
            属性[Element::空].Load("file/unit/element/002.png");
            属性[Element::樹].Load("file/unit/element/003.png");
            属性[Element::無].Load("file/unit/element/004.png");
        }
    }

    /**エフェクトや弾.*/
    namespace MEffect
    {
        Image 弾;

        static void Load()
        {
            弾.Load("file/effect/shot000.png");
        }
    }

    /**UI等のシステム.*/
    namespace MSystem
    {
        ImagePack マップチップ;
        ImagePack 枠画像[14];
        BmpFrame  フレーム[14];
        BmpFrame frameS[14];
		Image 矢印[4];
		EnumArray<Image,WitchType> カットイン;

        ImagePack マーク;

        Image チェック;

        Image 背景;

        static void Load()
        {
            マップチップ.Load("file/system/mapchip.png", 10, 10, 1);
            枠画像[0].Load("file/system/frame000.png", 9, 3, 3);
            枠画像[1].Load("file/system/frame001.png", 9, 3, 3);
            枠画像[2].Load("file/system/frame002.png", 9, 3, 3);
            枠画像[3].Load("file/system/frame003.png", 9, 3, 3);
            枠画像[4].Load("file/system/frame004.png", 9, 3, 3);
            枠画像[5].Load("file/system/frame005.png", 9, 3, 3);
            枠画像[6].Load("file/system/frame006.png", 9, 3, 3);
            枠画像[7].Load("file/system/frame007.png", 9, 3, 3);
            枠画像[8].Load("file/system/frame008.png", 9, 3, 3);
            枠画像[9].Load("file/system/frame009.png", 9, 3, 3);
            枠画像[10].Load("file/system/frame010.png", 9, 3, 3);
            枠画像[11].Load("file/system/frame011.png", 9, 3, 3);
            枠画像[12].Load("file/system/frame012.png", 9, 3, 3);
            枠画像[13].Load("file/system/frame013.png", 9, 3, 3);

            矢印[0].Load("file/system/tri0.png");
            矢印[1].Load("file/system/tri1.png");
            矢印[2].Load("file/system/tri2.png");
            矢印[3].Load("file/system/tri3.png");

            チェック.Load("file/system/tick.png");

			カットイン[WitchType::ライナ].Load("file/cut_in/lina.png");
			//カットイン[WitchType::ナツメ].Load("file/cut_in/natsume.png");
			//カットイン[WitchType::ルコウ].Load("file/cut_in/rukou.png");
			//カットイン[WitchType::ディアネラ].Load("file/cut_in/dianella.png");
			//カットイン[WitchType::ミナエ].Load("file/cut_in/minae.png");
			//カットイン[WitchType::トレニア].Load("file/cut_in/torenia.png");
			//カットイン[WitchType::ロチエ].Load("file/cut_in/rochie.png");
			//カットイン[WitchType::バロゥ].Load("file/cut_in/barrow.png");
			//カットイン[WitchType::フィオナ].Load("file/cut_in/fiona.png");
			//カットイン[WitchType::ナズナ].Load("file/cut_in/nazuna.png");
			//カットイン[WitchType::委員長].Load("file/cut_in/chairwoman.png");
			//カットイン[WitchType::ミルラ].Load("file/cut_in/myrra.png");

            for (int a = 0; a < 14; ++a)
            {
                フレーム[a].Make(&枠画像[a]);
                frameS[a].Make(&枠画像[a]);
            }

            背景.Load("file/system/back000.jpg");

            マーク.Load("file/system/mark.png", 4, 4, 1);
        }
    }

    /**BGM.*/
    namespace MMusic
    {
        Music 通常;
        Music 大魔法;
		Music メニュー;
		Music 勝利;
		Music 敗北;

        static void Load()
        {
            通常.Load("file/music/sentou.mp3");
			大魔法.Load("file/music/brave.mp3");
			メニュー.Load("file/music/menu.mp3");
			勝利.Load("file/music/syouri.mp3");
			敗北.Load("file/music/haiboku.mp3");

            通常.SetFadeInTime(0);
            通常.SetFadeOutTime(100);

            大魔法.SetFadeInTime(0);
            大魔法.SetFadeOutTime(100);
        }
    }

    /**効果音.*/
    namespace MSound
    {
        Sound Spチャージ完了;//Spが最大値になった時
        //Sound 攻撃;//ユニットの攻撃時の音、無し
        Sound 強化;//ユニット強化完了時
        Sound 売却;//ユニット売却完了時
        Sound 設置;//ユニット設置時
        Sound Wave;//次Wave進行時
        Sound 撃破;//敵撃破時
        Sound ダメージ;//ウィッチが被ダメ

        static void Load()
        {
            Spチャージ完了.Load("file/sound/eco00_r.wav",0.5);
            //攻撃.Load("file/sound/cursor18.wav");
            強化.Load("file/sound/power39.wav", 0.5);
            売却.Load("file/sound/coin06.wav", 0.5);
            設置.Load("file/sound/weapon00.wav", 0.5);
            Wave.Load("file/sound/power34.wav", 0.5);
            撃破.Load("file/sound/bom23.wav", 0.5);
            ダメージ.Load("file/sound/voice015.wav", 0.5);
        }
    }

    /**フォント.*/
    namespace MFont
    {
        Font fontS[5];

        ImagePack 英語;
        ImagePack 英影;
        ImagePack 黒数字;
        ImagePack 黒影;
        ImagePack 白数字;
        Image ゴシック12;
        Image ゴシック16;
		Image 黒ドット;
		Image 白ドット;

        static void Load()
        {
            //画像の読み込み
            英語.Load("file/font/font2.png", 30, 10, 3);
            英影.Load("file/font/font.png", 30, 10, 3);
            黒影.Load("file/font/font_num_black.png", 10, 10, 1);
            黒数字.Load("file/font/font_num_black2.png", 10, 10, 1);
            白数字.Load("file/font/font_num_white.png", 10, 10, 1);
            ゴシック12.Load("file/font/12.png");
            ゴシック16.Load("file/font/16.png");
			黒ドット.Load("file/font/dot_black.png");
			白ドット.Load("file/font/dot_white.png");

            //フォント幅調整_____a__b__c__d__e__f__g__h__i__j__k__l__m__n__o__p__q__r__s__t__u__v__w__x__y__z
            英語.AdjustWidth({ 1, 3, 2, 2, 3, 3, 1, 2, 4, 2, 3, 2, 0, 1, 1, 2, 1, 2, 2, 2, 1, 1, 0, 1, 2, 2 });
            英影.AdjustWidth({ 1, 3, 2, 2, 3, 3, 1, 2, 4, 2, 3, 2, 0, 1, 1, 2, 1, 2, 2, 2, 1, 1, 0, 1, 2, 2 });

            fontS[FontType::ゴシック小].LoadBMPFont(ゴシック12, "file/font/bmp_font_list.txt");
            fontS[FontType::ゴシック中].LoadBMPFont(ゴシック16, "file/font/bmp_font_list.txt");
            fontS[FontType::BMP黒].Load("", 6, 0);
            fontS[FontType::BMP黒影].Load("", 7, 0);
            fontS[FontType::BMP白].Load("", 6, 0);

            fontS[FontType::BMP黒].SetImageS("a", &英語, 26);
            fontS[FontType::BMP黒].SetImageS("A", &英語, 26);
            fontS[FontType::BMP黒].SetImageS("0", &黒数字, 10);
            fontS[FontType::BMP黒].SetImage("×", 英語[26]);
            fontS[FontType::BMP黒].SetImage("□", 英語[27]);
            fontS[FontType::BMP黒].SetImage("○", 英語[28]);
            fontS[FontType::BMP黒].SetImage("☆", 英語[29]);

            fontS[FontType::BMP黒影].SetImageS("a", &英影, 26);
            fontS[FontType::BMP黒影].SetImageS("A", &英影, 26);
            fontS[FontType::BMP黒影].SetImageS("0", &黒影, 10);
            fontS[FontType::BMP黒影].SetImage("×", 英影[26]);
            fontS[FontType::BMP黒影].SetImage("□", 英影[27]);
            fontS[FontType::BMP黒影].SetImage("○", 英影[28]);
            fontS[FontType::BMP黒影].SetImage("☆", 英影[29]);

            fontS[FontType::BMP白].SetImageS("0", &白数字, 10);

			fontS[FontType::BMP白].SetImage(".", &白ドット);
			fontS[FontType::BMP黒影].SetImage(".", &黒ドット);
        }

		void SetIcon()
		{

			//アイコンフォント
			//丸数字は味方
			fontS[FontType::ゴシック中].SetImage("①", MUnit::味方[UnitType::ライナ][1]);
			fontS[FontType::ゴシック中].SetImage("②", MUnit::味方[UnitType::ナツメ][1]);
			fontS[FontType::ゴシック中].SetImage("③", MUnit::味方[UnitType::ルコウ][1]);
			fontS[FontType::ゴシック中].SetImage("④", MUnit::味方[UnitType::ディアネラ][1]);
			fontS[FontType::ゴシック中].SetImage("⑤", MUnit::味方[UnitType::ミナエ][1]);
			fontS[FontType::ゴシック中].SetImage("⑥", MUnit::味方[UnitType::トレニア][1]);
			fontS[FontType::ゴシック中].SetImage("⑦", MUnit::味方[UnitType::ロチエ][1]);
			fontS[FontType::ゴシック中].SetImage("⑧", MUnit::味方[UnitType::バロゥ][1]);
			fontS[FontType::ゴシック中].SetImage("⑨", MUnit::味方[UnitType::フィオナ][1]);
			fontS[FontType::ゴシック中].SetImage("⑩", MUnit::味方[UnitType::ナズナ][1]);
			fontS[FontType::ゴシック中].SetImage("⑪", MUnit::味方[UnitType::委員長][1]);
			fontS[FontType::ゴシック中].SetImage("⑫", MUnit::味方[UnitType::ミルラ][1]);
			fontS[FontType::ゴシック中].SetImage("⑬", MUnit::味方[UnitType::兵士][1]);
			fontS[FontType::ゴシック中].SetImage("⑭", MUnit::味方[UnitType::傭兵][1]);
			fontS[FontType::ゴシック中].SetImage("⑮", MUnit::味方[UnitType::足軽][1]);
			fontS[FontType::ゴシック中].SetImage("⑯", MUnit::味方[UnitType::技師][1]);
			fontS[FontType::ゴシック中].SetImage("⑰", MUnit::味方[UnitType::勇者][1]);
			fontS[FontType::ゴシック中].SetImage("⑱", MUnit::味方[UnitType::剣士][1]);
			fontS[FontType::ゴシック中].SetImage("⑲", MUnit::味方[UnitType::剣豪][1]);
			fontS[FontType::ゴシック中].SetImage("⑳", MUnit::味方[UnitType::槍士][1]);
			fontS[FontType::ゴシック中].SetImage("㉑", MUnit::味方[UnitType::騎士][1]);
			fontS[FontType::ゴシック中].SetImage("㉒", MUnit::味方[UnitType::斧士][1]);
			fontS[FontType::ゴシック中].SetImage("㉓", MUnit::味方[UnitType::闘士][1]);
			fontS[FontType::ゴシック中].SetImage("㉔", MUnit::味方[UnitType::武闘家][1]);
			fontS[FontType::ゴシック中].SetImage("㉕", MUnit::味方[UnitType::師範][1]);
			fontS[FontType::ゴシック中].SetImage("㉖", MUnit::味方[UnitType::狩人][1]);
			fontS[FontType::ゴシック中].SetImage("㉗", MUnit::味方[UnitType::射手][1]);
			fontS[FontType::ゴシック中].SetImage("㉘", MUnit::味方[UnitType::僧侶][1]);
			fontS[FontType::ゴシック中].SetImage("㉙", MUnit::味方[UnitType::司祭][1]);
			fontS[FontType::ゴシック中].SetImage("㉚", MUnit::味方[UnitType::プリンス][1]);
			fontS[FontType::ゴシック中].SetImage("㉛", MUnit::味方[UnitType::プリンセス][1]);
			fontS[FontType::ゴシック中].SetImage("㉜", MUnit::味方[UnitType::術士][1]);
			fontS[FontType::ゴシック中].SetImage("㉝", MUnit::味方[UnitType::賢者][1]);
			fontS[FontType::ゴシック中].SetImage("㉞", MUnit::味方[UnitType::踊り子][1]);
			fontS[FontType::ゴシック中].SetImage("㉟", MUnit::味方[UnitType::軍師][1]);
			fontS[FontType::ゴシック中].SetImage("㊱", MUnit::味方[UnitType::将軍][1]);
			fontS[FontType::ゴシック中].SetImage("㊲", MUnit::味方[UnitType::執事][1]);
			fontS[FontType::ゴシック中].SetImage("㊳", MUnit::味方[UnitType::給仕][1]);
			fontS[FontType::ゴシック中].SetImage("㊴", MUnit::味方[UnitType::料理人][1]);
			fontS[FontType::ゴシック中].SetImage("㊵", MUnit::味方[UnitType::盗賊][1]);
			fontS[FontType::ゴシック中].SetImage("㊶", MUnit::味方[UnitType::忍者][1]);
			fontS[FontType::ゴシック中].SetImage("㊷", MUnit::味方[UnitType::くノ一][1]);

			//ローマ数字は敵
			fontS[FontType::ゴシック中].SetImage("㊸", MUnit::敵[EnemyType::ゼリー][1]);
			fontS[FontType::ゴシック中].SetImage("㊹", MUnit::敵[EnemyType::ゴブリン][1]);
			fontS[FontType::ゴシック中].SetImage("㊺", MUnit::敵[EnemyType::ケットシー][1]);
			fontS[FontType::ゴシック中].SetImage("㊻", MUnit::敵[EnemyType::オーガ][1]);
			fontS[FontType::ゴシック中].SetImage("㊼", MUnit::敵[EnemyType::コボルド][1]);
			fontS[FontType::ゴシック中].SetImage("㊽", MUnit::敵[EnemyType::ゴーレム][1]);
			fontS[FontType::ゴシック中].SetImage("㊾", MUnit::敵[EnemyType::ケルベロス][1]);
			fontS[FontType::ゴシック中].SetImage("㊿", MUnit::敵[EnemyType::スケルトン][1]);
			fontS[FontType::ゴシック中].SetImage("Ⅰ", MUnit::敵[EnemyType::シャーマン][1]);
			fontS[FontType::ゴシック中].SetImage("Ⅱ", MUnit::敵[EnemyType::ゼリー王][1]);
			fontS[FontType::ゴシック中].SetImage("Ⅲ", MUnit::敵[EnemyType::マーマン][1]);
			fontS[FontType::ゴシック中].SetImage("Ⅳ", MUnit::敵[EnemyType::インプ][1]);
			fontS[FontType::ゴシック中].SetImage("Ⅴ", MUnit::敵[EnemyType::トレント][1]);//青ゴーレム
			fontS[FontType::ゴシック中].SetImage("Ⅵ", MUnit::敵[EnemyType::グリフィン][1]);
			fontS[FontType::ゴシック中].SetImage("Ⅶ", MUnit::敵[EnemyType::ドラゴン][1]);
		}
    }

    static void LoadMaterial()
    {
        MFont::Load();

        Loading::Start();

        MUnit::Load();
        MUnit::Load();
        MIcon::Load();
        MEffect::Load();
        MSystem::Load();

        MMusic::Load();
        MSound::Load();

        Loading::End();
    }
}