﻿//Copyright © 
//[License]GNU Affero General Public License, version 3
//[Contact]
#pragma once
#include <SDXFrameWork.h>
#include "GUI_Factory.h"
#include "../System/Material.h"
#include "../Struct/HelpData.h"
#include "SceneHelpSub.h"

namespace SDX_TD
{
    using namespace SDX;

    class SceneHelp : public SDX::IScene
    {
    public:
        //@Define
		UI_Button 項目1 = { 125, {66,8,280,40} , 0.000000,3};
		UI_Button 項目11 = { 320, {356,8,280,40} , 0.000000,3};
		UI_Button 項目2 = { 334, {66,55,280,40} , 0.000000,3};
		UI_Button 項目3 = { 335, {66,102,280,40} , 0.000000,3};
		UI_Button 項目4 = { 336, {66,149,280,40} , 0.000000,3};
		UI_Button 項目5 = { 337, {66,196,280,40} , 0.000000,3};
		UI_Button 項目6 = { 338, {66,243,280,40} , 0.000000,3};
		UI_Button 項目8 = { 339, {66,338,280,40} , 0.000000,3};
		UI_Button 項目7 = { 340, {66,290,280,40} , 0.000000,3};
		UI_Button 項目9 = { 341, {66,385,280,40} , 0.000000,3};
		UI_Button 項目10 = { 342, {66,431,280,40} , 0.000000,3};
		UI_Button 項目12 = { 343, {356,55,280,40} , 0.000000,3};
		UI_Button 項目20 = { 344, {356,431,280,40} , 0.000000,3};
		UI_Button 項目19 = { 345, {356,385,280,40} , 0.000000,3};
		UI_Button 項目15 = { 346, {357,196,280,40} , 0.000000,3};
		UI_Button 項目14 = { 347, {356,149,280,40} , 0.000000,3};
		UI_Button 項目17 = { 348, {357,290,280,40} , 0.000000,3};
		UI_Button 項目18 = { 349, {357,338,280,40} , 0.000000,3};
		UI_Button 項目13 = { 350, {356,102,280,40} , 0.000000,3};
		UI_Button 項目16 = { 351, {357,243,280,40} , 0.000000,3};
        //@End
		UI_Button* 項目S[20];

        SceneHelp()
        {
            LoadGUI();
            Init();            
        }

        //初期化
        void Init() override
        {
			項目S[0] = &項目1;
			項目S[1] = &項目2;
			項目S[2] = &項目3;
			項目S[3] = &項目4;
			項目S[4] = &項目5;
			項目S[5] = &項目6;
			項目S[6] = &項目7;
			項目S[7] = &項目8;
			項目S[8] = &項目9;
			項目S[9] = &項目10;
			項目S[10] = &項目11;
			項目S[11] = &項目12;
			項目S[12] = &項目13;
			項目S[13] = &項目14;
			項目S[14] = &項目15;
			項目S[15] = &項目16;
			項目S[16] = &項目17;
			項目S[17] = &項目18;
			項目S[18] = &項目19;
			項目S[19] = &項目20;
        }

        //終了時
        void Final() override
        {
        }

        //更新
        void Update() override
        {
			for (int a = 0;a < 20;++a)
			{
				if (項目S[a]->isClick())
				{
					SceneHelpSub::Call(this,a);
				}
			}

            /*//Update
			if (項目20.isClick())
			{
				表示画像 = nullptr;
				isヘルプ表示 = true;
				文章 = "[クレジット](敬称略、詳細はreadme.txt)\n"
					"[制作･著作･その他色々]\n"
					"(`･@･)\n"
					"[イラスト]\n"
					"カルディア03\n"
					"[ライブラリ]\n"
					"SDL 2.0\n"
					"SDXFramework 0.13\n"
					"libjpeg Copyright(c)1991-2012,Thomas G.Lane,Guido Vollbeding.\n"
					"libmikmod Copyright(c) Mikmod.\n"
					"smpeg Copyright(c)Loki Software.\n"
					"[グラフィック素材]\n"
					"ドットワールド\n"
					"エトリエ\n"
					"臼井の会\n"
					"white cat\n"
					"ぴぽや\n"
					"[音声素材]\n"
					"FREEDOM HOUSE 2nd\n"
					"ザ・マッチメイカァズ 2nd\n"
					"[フォント素材]\n"
					"IPAフォント\n";
			}
            //End*/
        }

        //描画
        void Draw() override
        {
#ifdef _DEBUG			
            if (Input::key.Return.on){ LoadGUI(); }
#endif
            /*Draw
			MSystem::frameS[項目1.frameNo].Draw(項目1.rect);
			MSystem::frameS[項目11.frameNo].Draw(項目11.rect);
			MSystem::frameS[項目2.frameNo].Draw(項目2.rect);
			MSystem::frameS[項目3.frameNo].Draw(項目3.rect);
			MSystem::frameS[項目4.frameNo].Draw(項目4.rect);
			MSystem::frameS[項目5.frameNo].Draw(項目5.rect);
			MSystem::frameS[項目6.frameNo].Draw(項目6.rect);
			MSystem::frameS[項目8.frameNo].Draw(項目8.rect);
			MSystem::frameS[項目7.frameNo].Draw(項目7.rect);
			MSystem::frameS[項目9.frameNo].Draw(項目9.rect);
			MSystem::frameS[項目10.frameNo].Draw(項目10.rect);
			MSystem::frameS[項目12.frameNo].Draw(項目12.rect);
			MSystem::frameS[項目20.frameNo].Draw(項目20.rect);
			MSystem::frameS[項目19.frameNo].Draw(項目19.rect);
			MSystem::frameS[項目15.frameNo].Draw(項目15.rect);
			MSystem::frameS[項目14.frameNo].Draw(項目14.rect);
			MSystem::frameS[項目17.frameNo].Draw(項目17.rect);
			MSystem::frameS[項目18.frameNo].Draw(項目18.rect);
			//MSystem::frameS[項目13.frameNo].Draw(項目13.rect);
			//MSystem::frameS[項目16.frameNo].Draw(項目16.rect);
            //End*/
            //MFont::fontS[1].DrawRotate(項目20.rect.GetCenter(),2,0, Color::Black, "Credit");

			for (int a = 0;a < 20;++a)
			{
				項目S[a]->DrawText(MFont::fontS[1], HelpDataS[a].題名.c_str() , 2);
			}

			/*
            if (isヘルプ表示)
            {
                //枠
                MSystem::frameS[5].Draw({ 80, 20, 540, 440 });
				//ヘルプ画像
				if (表示画像 != nullptr)
				{
					//画像有り
					表示画像->Draw({100,40});
					MFont::fontS[1].Draw({ 100, 40 + 表示画像->GetHeight() }, Color::White, 文章);
				}
				else
				{
					//画像無し
					MFont::fontS[1].Draw({ 100, 40 }, Color::White, 文章);
				}
            }
			*/
        }

        void LoadGUI() override
        {
#ifndef _DEBUG
            return;
#endif
            //@Load
			SDX::GUIData guiData = SDX::TMXtoGUI( TMX_FILE_NAME , "SceneHelp", GUI_Factory);

			項目1 = *dynamic_cast<UI_Button*>(guiData.dataS[0].get());
			項目11 = *dynamic_cast<UI_Button*>(guiData.dataS[1].get());
			項目2 = *dynamic_cast<UI_Button*>(guiData.dataS[2].get());
			項目3 = *dynamic_cast<UI_Button*>(guiData.dataS[3].get());
			項目4 = *dynamic_cast<UI_Button*>(guiData.dataS[4].get());
			項目5 = *dynamic_cast<UI_Button*>(guiData.dataS[5].get());
			項目6 = *dynamic_cast<UI_Button*>(guiData.dataS[6].get());
			項目8 = *dynamic_cast<UI_Button*>(guiData.dataS[7].get());
			項目7 = *dynamic_cast<UI_Button*>(guiData.dataS[8].get());
			項目9 = *dynamic_cast<UI_Button*>(guiData.dataS[9].get());
			項目10 = *dynamic_cast<UI_Button*>(guiData.dataS[10].get());
			項目12 = *dynamic_cast<UI_Button*>(guiData.dataS[11].get());
			項目20 = *dynamic_cast<UI_Button*>(guiData.dataS[12].get());
			項目19 = *dynamic_cast<UI_Button*>(guiData.dataS[13].get());
			項目15 = *dynamic_cast<UI_Button*>(guiData.dataS[14].get());
			項目14 = *dynamic_cast<UI_Button*>(guiData.dataS[15].get());
			項目17 = *dynamic_cast<UI_Button*>(guiData.dataS[16].get());
			項目18 = *dynamic_cast<UI_Button*>(guiData.dataS[17].get());
			項目13 = *dynamic_cast<UI_Button*>(guiData.dataS[18].get());
			項目16 = *dynamic_cast<UI_Button*>(guiData.dataS[19].get());
            //@End
        }
    };
}
