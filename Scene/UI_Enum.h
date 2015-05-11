﻿//Copyright © 2014 SDXFramework
//[License]GNU Affero General Public License, version 3
//[Contact]http://sourceforge.jp/projects/dxframework/
#pragma once

namespace SDX_TD
{
	enum ObjectID
	{
		SceneMenu_全体枠 = 99,
		SceneMenu_Storyタグ = 67,
		SceneMenu_Questタグ = 72,
		SceneMenu_Freeタグ = 73,
		SceneMenu_Replayタグ = 74,
		SceneMenu_Archiveタグ = 75,
		SceneMenu_Skillタグ = 76,
		SceneMenu_Helpタグ = 77,
		SceneMenu_Configタグ = 78,
		SceneQuest_難易度情報 = 65,
		SceneQuest_ステージ一覧 = 29,
		SceneQuest_開始 = 30,
		SceneQuest_難易度－ = 60,
		SceneQuest_難易度＋ = 61,
		SceneQuest_ウィッチ一覧 = 63,
		SceneQuest_マップ情報 = 64,
		SceneQuest_面数Minus = 107,
		SceneQuest_ステージA = 109,
		SceneQuest_ステージB = 110,
		SceneQuest_ステージC = 111,
		SceneQuest_ステージD = 112,
		SceneQuest_面数Plus = 113,
		SceneQuest_難易度 = 114,
		SceneQuest_Wave数 = 115,
		SceneQuest_出現数 = 116,
		SceneQuest_HP補正 = 117,
		SceneQuest_Lv補正 = 118,
		SceneQuest_ウィッチアイコン = 119,
		SceneQuest_シングル_カップル = 31,
		SceneQuest_トライアル = 59,
		SceneQuest_ウィッチ名 = 121,
		SceneQuest_星 = 122,
		SceneQuest_スコア = 123,
		SceneQuest_ハイスコア = 240,
		SceneConfig_効果音＋ = 90,
		SceneConfig_効果音－ = 91,
		SceneConfig_BGM－ = 92,
		SceneConfig_BGM＋ = 93,
		SceneConfig_グリッド = 94,
		SceneConfig_敵HP = 95,
		SceneConfig_エフェクト表示 = 96,
		SceneConfig_タッチ操作 = 97,
		SceneConfig_リプレイ保存 = 98,
		SceneConfig_効果音 = 100,
		SceneConfig_BGMゲージ = 102,
		SceneConfig_効果音ゲージ = 103,
		SceneConfig_初期配置 = 124,
		SceneConfig_グリッドChk = 227,
		SceneConfig_敵HPChk = 229,
		SceneConfig_エフェクト表示Chk = 230,
		SceneConfig_リプレイ保存Chk = 231,
		SceneConfig_タッチ操作Chk = 232,
		SceneConfig_初期配置Chk = 233,
		SceneConfig_BGM = 234,
		SceneConfig_画面サイズ = 251,
		SceneConfig_画面サイズChk = 252,
		SceneConfig_おまけChk = 254,
		SceneConfig_おまけ = 255,
		SceneArchive_実装中～ = 104,
		SceneHelp_クレジット = 125,
		SceneReplay_リプレイ情報 = 127,
		SceneReplay_開始 = 128,
		SceneReplay_スコア = 129,
		SceneReplay_スクロールバー = 132,
		SceneReplay_マップ情報 = 133,
		SceneReplay_リプレイ選択 = 135,
		SceneReplay_ウィッチ = 139,
		SceneReplay_トライアル = 142,
		SceneReplay_結果 = 144,
		SceneReplay_ステージ一覧 = 145,
		SceneReplay_下スクロール = 146,
		SceneReplay_上スクロール = 148,
		SceneReplay_難易度 = 246,
		SceneReplay_カップル = 248,
		SceneSkill_攻撃 = 162,
		SceneSkill_リセット = 175,
		SceneSkill_レベル = 177,
		SceneSkill_残りポイント = 178,
		SceneSkill_拡散 = 179,
		SceneSkill_防壊 = 180,
		SceneSkill_節約 = 181,
		SceneSkill_対獣 = 182,
		SceneSkill_対闇 = 183,
		SceneSkill_対人 = 190,
		SceneSkill_対竜 = 191,
		SceneSkill_連射 = 192,
		SceneSkill_体力 = 193,
		SceneSkill_麻痺 = 194,
		SceneSkill_回収 = 195,
		SceneSkill_幸運 = 196,
		SceneSkill_射程 = 197,
		SceneSkill_対水 = 198,
		SceneSkill_鈍足 = 199,
		SceneSkill_魔力 = 200,
		SceneSkill_強化 = 201,
		SceneSkill_吹飛 = 202,
		SceneSkill_必殺 = 203,
		SceneSkill_試練 = 204,
		SceneSkill_対樹 = 205,
		SceneSkill_支援 = 206,
		SceneSkill_逆境 = 207,
		SceneSkill_スキル説明 = 209,
		SceneStory_実装中～ = 106,
		SceneTitle_題字 = 88,
		SceneTitle_押して下さい = 89,
		ScenePause_あきらめる = 79,
		ScenePause_やり直す = 80,
		ScenePause_続ける = 81,
		SceneResult_リプレイ保存 = 83,
		SceneResult_リトライ = 84,
		SceneResult_終了 = 85,
		SceneResult_全体枠 = 86,
		SceneResult_Result = 87,
		SceneResult_最終スコア = 151,
		SceneResult_撃破スコア = 153,
		SceneResult_難易度補正 = 154,
		SceneResult_体力補正 = 155,
		SceneResult_獲得経験値 = 156,
		SceneWitch_全体枠 = 210,
		SceneWitch_ライナ = 211,
		SceneWitch_決定 = 212,
		SceneWitch_ルコウ = 213,
		SceneWitch_ロチエ = 216,
		SceneWitch_ミナエ = 217,
		SceneWitch_委員長 = 218,
		SceneWitch_フィオナ = 219,
		SceneWitch_ディアネラ = 220,
		SceneWitch_トレニア = 221,
		SceneWitch_ミルラ = 222,
		SceneWitch_バロゥ = 223,
		SceneWitch_ナズナ = 224,
		SceneWitch_ナツメ = 225,
		SceneWitch_キャンセル = 244,
	};

	enum ResourceID
	{
	};
}
