﻿//Copyright © 2014 (´･@･)
//[License]GNU Affero General Public License, version 3
//[Contact]http://tacoika.blog87.fc2.com/
#pragma once
#include "TDSystem.h"

namespace SDX_TD
{
	namespace WITCH
	{
		using namespace SDX;
		/**魔女.*/

		class Witch : public WitchData
		{
		public:
			WitchType 種類;
			WitchData st;//レベル上昇や大魔法発動補正前のステータス
			
			//固定パラメータ
			Element 属性;
			UnitType 魔法タイプ[12];
			int    召喚数[12];

			//変動パラメータ
			int MP = 1000;
			double SP = 0;
			double 最大SP = 1000;
			int    レベル;
			int    経験値;
			int    大魔法残り時間;
			int    被ダメージ;

			//戦闘開始時の初期化処理
			void Init(){};

			/**配置に必要なMPを取得.*/
			int GetReqMP(UnitType 魔法種 , int Lv = 0)
			{
				return int(UnitDataS[魔法種].コスト[Lv] * MP消費);
			}

			/**被ダメージ処理.*/
			void Damage()
			{
				SP += 最大SP / 20;
				if (TDSystem::Hp > 0){ TDSystem::Hp--; }
			}

			//大魔法発動時の性能計算、効果処理
			virtual void 大魔法発動() = 0;

			/**通常時の性能計算.*/
			/**MP等は初期化しない*/
			void 補正計算()
			{
				//stを代入
				攻撃補正 = st.攻撃補正;
				連射補正 = st.連射補正;
				範囲補正 = st.範囲補正;
				射程補正 = st.射程補正;
				支援補正 = st.支援補正;
				弾速補正 = st.弾速補正;

				MP消費 = st.MP消費;
				MP獲得 = st.MP獲得;
				回収率 = st.回収率;
				回収速度 = st.回収速度;
				強化速度 = st.強化速度;

				弱点補正 = st.弱点補正;

				特殊補正[DebuffType::吹飛] = st.特殊補正[DebuffType::吹飛];
				特殊補正[DebuffType::防壊] = st.特殊補正[DebuffType::防壊];
				特殊補正[DebuffType::麻痺] = st.特殊補正[DebuffType::麻痺];
				特殊補正[DebuffType::鈍足] = st.特殊補正[DebuffType::鈍足];

				大魔法時間 = st.大魔法時間;
				必要SP = st.必要SP;

				逆境補正 = st.逆境補正;//ライフ-1につき1%攻撃力が上がる

				//アイテムや成長補正
				if (!TDSystem::isトライアル)
				{
					レベル補正();
					アイテム補正();
				}
			}

			//レベルによる補正計算
			virtual void レベル補正() = 0;

			//アイテムによる補正計算
			void アイテム補正()
			{
			
			
			};
		};

		namespace
		{
			std::unique_ptr<Witch> Main;//現在アクティブなウィッチ
			std::unique_ptr<Witch> Sub;//控えのウィッチ
		}

		class ライナ : public Witch
		{
		public:
			ライナ()
			{
				種類 = WitchType::ライナ;
				属性 = Element::炎;

				st.攻撃補正 = 1.05;//やや強い
				st.連射補正 = 1.05;//やや強い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.02;//通常の2倍

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::ライナ;

				魔法タイプ[1] = UnitType::兵士;
				魔法タイプ[2] = UnitType::技師;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::槍士;
				魔法タイプ[5] = UnitType::斧士;
				魔法タイプ[6] = UnitType::武闘家;
				魔法タイプ[7] = UnitType::狩人;
				魔法タイプ[8] = UnitType::術士;
				魔法タイプ[9] = UnitType::踊り子;
				魔法タイプ[10] = UnitType::執事;
				魔法タイプ[11] = UnitType::盗賊;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};

		class ナツメ : public Witch
		{
		public:
			ナツメ()
			{
				種類 = WitchType::ナツメ;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::ルコウ;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::狩人;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::盗賊;
				魔法タイプ[5] = UnitType::踊り子;
				魔法タイプ[6] = UnitType::射手;//B
				魔法タイプ[7] = UnitType::剣豪;
				魔法タイプ[8] = UnitType::勇者;
				魔法タイプ[9] = UnitType::賢者;
				魔法タイプ[10] = UnitType::給仕;
				魔法タイプ[11] = UnitType::料理人;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};
		class ルコウ : public Witch
		{
		public:
			ルコウ()
			{
				種類 = WitchType::ルコウ;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::ルコウ;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::狩人;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::盗賊;
				魔法タイプ[5] = UnitType::踊り子;
				魔法タイプ[6] = UnitType::射手;//B
				魔法タイプ[7] = UnitType::剣豪;
				魔法タイプ[8] = UnitType::勇者;
				魔法タイプ[9] = UnitType::賢者;
				魔法タイプ[10] = UnitType::給仕;
				魔法タイプ[11] = UnitType::料理人;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};

		class ディアネラ : public Witch
		{
		public:
			ディアネラ()
			{
				種類 = WitchType::ディアネラ;
				属性 = Element::空;

				st.攻撃補正 = 1.0;//普通
				st.連射補正 = 1.0;
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 0.9;//10%OFF
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::ディアネラ;

				魔法タイプ[1] = UnitType::兵士;//A
				魔法タイプ[2] = UnitType::技師;
				魔法タイプ[3] = UnitType::斧士;
				魔法タイプ[4] = UnitType::術士;
				魔法タイプ[5] = UnitType::執事;

				魔法タイプ[6] = UnitType::騎士;//B
				魔法タイプ[7] = UnitType::闘士;
				魔法タイプ[8] = UnitType::司祭;
				魔法タイプ[9] = UnitType::くノ一;
				魔法タイプ[10] = UnitType::将軍;
				魔法タイプ[11] = UnitType::COUNT;//None
			}

			//獲得資金1.5倍
			//殆どの能力が1.1倍
			void 大魔法発動() override
			{
				MP獲得 *= 1.5;
				攻撃補正 *= 1.1;
				射程補正 *= 1.1;
				連射補正 *= 1.1;
			}

			void レベル補正() override
			{}
		};

		class ミナエ : public Witch
		{
		public:
			ミナエ()
			{
				種類 = WitchType::ミナエ;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::ミナエ;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::狩人;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::盗賊;
				魔法タイプ[5] = UnitType::踊り子;
				魔法タイプ[6] = UnitType::射手;//B
				魔法タイプ[7] = UnitType::剣豪;
				魔法タイプ[8] = UnitType::勇者;
				魔法タイプ[9] = UnitType::賢者;
				魔法タイプ[10] = UnitType::給仕;
				魔法タイプ[11] = UnitType::料理人;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};
		class トレニア : public Witch
		{
		public:
			トレニア()
			{
				種類 = WitchType::トレニア;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::トレニア;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::狩人;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::盗賊;
				魔法タイプ[5] = UnitType::踊り子;
				魔法タイプ[6] = UnitType::射手;//B
				魔法タイプ[7] = UnitType::剣豪;
				魔法タイプ[8] = UnitType::勇者;
				魔法タイプ[9] = UnitType::賢者;
				魔法タイプ[10] = UnitType::給仕;
				魔法タイプ[11] = UnitType::料理人;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};
		class ロチエ : public Witch
		{
		public:
			ロチエ()
			{
				種類 = WitchType::ロチエ;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::ロチエ;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::狩人;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::盗賊;
				魔法タイプ[5] = UnitType::踊り子;
				魔法タイプ[6] = UnitType::射手;//B
				魔法タイプ[7] = UnitType::剣豪;
				魔法タイプ[8] = UnitType::勇者;
				魔法タイプ[9] = UnitType::賢者;
				魔法タイプ[10] = UnitType::給仕;
				魔法タイプ[11] = UnitType::料理人;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};

		class バロゥ : public Witch
		{
		public:
			バロゥ()
			{
				種類 = WitchType::バロゥ;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;
				
				魔法タイプ[0] = UnitType::バロゥ;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::技師;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::騎士;
				魔法タイプ[5] = UnitType::師範;
				魔法タイプ[6] = UnitType::狩人;//B
				魔法タイプ[7] = UnitType::射手;
				魔法タイプ[8] = UnitType::賢者;
				魔法タイプ[9] = UnitType::将軍;
				魔法タイプ[10] = UnitType::執事;
				魔法タイプ[11] = UnitType::盗賊;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};

		class フィオナ : public Witch
		{
		public:
			フィオナ()
			{
				種類 = WitchType::フィオナ;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::フィオナ;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::狩人;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::盗賊;
				魔法タイプ[5] = UnitType::踊り子;
				魔法タイプ[6] = UnitType::射手;//B
				魔法タイプ[7] = UnitType::剣豪;
				魔法タイプ[8] = UnitType::勇者;
				魔法タイプ[9] = UnitType::賢者;
				魔法タイプ[10] = UnitType::給仕;
				魔法タイプ[11] = UnitType::料理人;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};
		class ナズナ : public Witch
		{
		public:
			ナズナ()
			{
				種類 = WitchType::ナズナ;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::ナズナ;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::狩人;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::盗賊;
				魔法タイプ[5] = UnitType::踊り子;
				魔法タイプ[6] = UnitType::射手;//B
				魔法タイプ[7] = UnitType::剣豪;
				魔法タイプ[8] = UnitType::勇者;
				魔法タイプ[9] = UnitType::賢者;
				魔法タイプ[10] = UnitType::給仕;
				魔法タイプ[11] = UnitType::料理人;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};
		class 委員長 : public Witch
		{
		public:
			委員長()
			{
				種類 = WitchType::委員長;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::委員長;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::狩人;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::盗賊;
				魔法タイプ[5] = UnitType::踊り子;
				魔法タイプ[6] = UnitType::射手;//B
				魔法タイプ[7] = UnitType::剣豪;
				魔法タイプ[8] = UnitType::勇者;
				魔法タイプ[9] = UnitType::賢者;
				魔法タイプ[10] = UnitType::給仕;
				魔法タイプ[11] = UnitType::料理人;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};

		class ミルラ : public Witch
		{
		public:
			ミルラ()
			{
				種類 = WitchType::ミルラ;
				属性 = Element::空;

				st.攻撃補正 = 0.7;//低い
				st.連射補正 = 1.5;//早い
				st.範囲補正 = 1.0;
				st.射程補正 = 1.0;
				st.支援補正 = 1.0;
				st.弾速補正 = 1.0;

				st.MP消費 = 1.0;
				st.MP獲得 = 1.0;
				st.回収率 = 0.7;
				st.回収速度 = 1.0;
				st.強化速度 = 1.0;

				st.弱点補正 = 1.1;
				st.特殊補正[DebuffType::吹飛] = 1.0;
				st.特殊補正[DebuffType::防壊] = 1.0;
				st.特殊補正[DebuffType::麻痺] = 1.0;
				st.特殊補正[DebuffType::鈍足] = 1.0;

				st.大魔法時間 = 3000;
				st.必要SP = 1.0;
				st.逆境補正 = 0.01;

				st.初期HP = 20;
				st.初期MP = 50;

				st.詠唱回数補正 = 1.0;

				魔法タイプ[0] = UnitType::委員長;
				魔法タイプ[1] = UnitType::足軽;//A
				魔法タイプ[2] = UnitType::狩人;
				魔法タイプ[3] = UnitType::剣士;
				魔法タイプ[4] = UnitType::盗賊;
				魔法タイプ[5] = UnitType::踊り子;
				魔法タイプ[6] = UnitType::射手;//B
				魔法タイプ[7] = UnitType::剣豪;
				魔法タイプ[8] = UnitType::勇者;
				魔法タイプ[9] = UnitType::賢者;
				魔法タイプ[10] = UnitType::給仕;
				魔法タイプ[11] = UnitType::料理人;
			}

			void 大魔法発動() override
			{}

			void レベル補正() override
			{}
		};
	}
}