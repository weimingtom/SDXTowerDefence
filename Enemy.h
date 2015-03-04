﻿//Copyright © 2014 (´･@･)
//[License]GNU Affero General Public License, version 3
//[Contact]http://tacoika.blog87.fc2.com/
#pragma once
#include "Object.h"
#include "Shot.h"
#include "DataS.h"
#include "Design.h"
#include "Witch.h"

namespace SDX_TD
{
	using namespace SDX;
	class IEnemy :public IObject
	{
	public:
		const static int 判定大きさ = 14;
		const static int ボスダメージ = 2;

		const EnemyData *st;
		MoveType 移動種;
		IEnemy*		next;//当たり判定チェイン用
		int		レベル = 0;
		int		方向 = 5;
		double	最大HP = 0;
		double	残りHP = 0;
		int		防御力 = 0;
		double	回避力 = 0;
		double	鈍足率 = 1.0;
		double	再生力 = 0;
		int		鈍足時間 = 0;
		int		麻痺時間 = 0;
		double	吹き飛びX = 0;
		double	吹き飛びY = 0;
		bool	isBoss = false;

		int     スコア;

		IEnemy(IShape &図形, ISprite &描画方法, EnemyData* st, int Lv, bool isBoss) :
			IObject(図形, 描画方法),
			isBoss(isBoss),
			st(st),
			レベル(Lv),
			移動種(st->移動種)
		{
			スコア = int(st->スコア * (1.0 + (double)レベル / 30 ));
			最大HP = st->最大HP * (1.0 + (レベル)* 0.2 + (レベル) * (レベル) * 0.06) * DifficultyDataS[TDSystem::難易度].HP補正[TDSystem::isトライアル];
			防御力 = int(st->防御力 * レベル);

			if (isBoss)
			{
				スコア *= 16;
				最大HP *= 16;
				防御力 *= 2;
			}

			残りHP = 最大HP;
		}

		virtual ~IEnemy(){}

		/**死亡時、基本処理.*/
		virtual void Dead() = 0;

		void 方向更新()
		{
			switch (移動種)
			{
			case MoveType::空:
				方向 = SStage->land.空路.方向計算(方向, (int)GetX(), (int)GetY());
				break;
			case MoveType::陸:
				方向 = SStage->land.陸路.方向計算(方向, (int)GetX(), (int)GetY());
				break;
			case MoveType::水:
				方向 = SStage->land.水路.方向計算(方向, (int)GetX(), (int)GetY());
				break;
			}
		}

		/**特殊地形による移動量補正.*/
		void 地形処理(double &移動量X, double &移動量Y)
		{
			//飛んでる敵は影響無し
			if (移動種 == MoveType::空) return;

			int x = (int)(GetX() / CHIP_SIZE);
			int y = (int)(GetY() / CHIP_SIZE);
			auto 地形種 = SStage->land.地形[x][y];

			switch (地形種)
			{
			case SDX_TD::ChipType::沼:
				if (移動種 == MoveType::水){ break; }
				移動量X /= 2;
				移動量Y /= 2;
				break;
			default:
				break;
			}
		}

		/**移動不可マスへのめり込み回避.*/
		void 地形衝突()
		{
			//はみ出ている量
			const int X差 = (int)GetX() % CHIP_SIZE - 判定大きさ / 2;
			const int Y差 = (int)GetY() % CHIP_SIZE - 判定大きさ / 2;

			//各方向にはみ出ているか
			const bool is上 = Y差 < 0;
			const bool is下 = Y差 > 0;
			const bool is左 = X差 < 0;
			const bool is右 = X差 > 0;

			bool 衝突[9] = {};

			//平面にめりこみ
			if (is上) { 衝突[1] = SStage->land.Check地形(GetX(), GetY() - 6, 移動種); }
			if (is左) { 衝突[3] = SStage->land.Check地形(GetX() - 6, GetY(), 移動種); }
			if (is右) { 衝突[5] = SStage->land.Check地形(GetX() + 6, GetY(), 移動種); }
			if (is下) { 衝突[7] = SStage->land.Check地形(GetX() - 6, GetY() + 6, 移動種); }

			//角にめりこみ
			if (is上 && is左){ 衝突[0] = SStage->land.Check地形(GetX() - 6, GetY() - 6, 移動種); }
			if (is上 && is右){ 衝突[2] = SStage->land.Check地形(GetX() + 6, GetY() - 6, 移動種); }
			if (is下 && is左){ 衝突[6] = SStage->land.Check地形(GetX() - 6, GetY() + 6, 移動種); }
			if (is下 && is右){ 衝突[8] = SStage->land.Check地形(GetX() + 6, GetY() + 6, 移動種); }

			//現在のマスが移動不可能
			if (SStage->land.Check地形(GetX(), GetY(), 移動種))
			{
				Move(Rand::Get(-1, 1), Rand::Get(-1, 1));
				return;
			}

			double x = 0, y = 0;

			//斜め衝突
			if (衝突[0] && 衝突[1] == 衝突[3]){ x = 1; y = 1; }
			if (衝突[2] && 衝突[1] == 衝突[5]){ x = -1;y = 1; }
			if (衝突[6] && 衝突[3] == 衝突[7]){ x = 1; y = -1; }
			if (衝突[8] && 衝突[5] == 衝突[7]){ x = -1;y= -1; }
			if (衝突[1]){ y = 1; }
			if (衝突[3]){ x = 1; }
			if (衝突[5]){ x = -1; }
			if (衝突[7]){ y = -1; }

			Move(x, y);
		}

		/**@todo 乱数使用がリプレイ機能に影響.*/
		void Draw() const
		{
			int アニメ = 0;
			bool 反転 = false;

			switch (方向)
			{
			case 0:
			case 1:
				アニメ = 3;
				break;
			case 2:
			case 5:
				アニメ = 6;
				反転 = true;
				break;
			case 3:
			case 6:
				アニメ = 6;
				break;
			case 7:
			case 8:
				アニメ = 0;
				break;
			}

			switch (timer / 10 % 4)
			{
			case 0:
				break;
			case 1:
			case 3:
				アニメ += 1;
				break;
			case 2:
				アニメ += 2;
				break;
			}

			Point pos = {GetX(),GetY()};
			const auto image = MUnit::敵[st->種族][アニメ];

			if (鈍足時間 > 0)
			{
				image->SetColor({ 0, 255, 0 });
			}
			if (麻痺時間 > 0)
			{ 
				pos.Move(Rand::Get(-3, 3), Rand::Get(-3, 3));
			}

			image->DrawRotate(pos, 1 + isBoss, 0, 反転);
			image->SetColor(Color::White);

			//Hpゲージ
			if (TDSystem::isHPゲージ)
			{
				int life = int(残りHP * 32 / 最大HP);

				Color color = Color::Blue;
				if (life <= 8)
				{
					color = Color::Red;
				}
				else if (life <= 16)
				{
					color = { 255, 128, 0 };
				}

				if (isBoss)
				{
					Drawing::Rect({ GetX() - 16, GetY() + 16, 32, 2 }, Color::Black);
					Drawing::Rect({ GetX() - 16, GetY() + 16, life, 2 }, color);
				}
				else
				{
					Drawing::Rect({ GetX() - 8, GetY() + 8, 16, 2 }, Color::Black);
					Drawing::Rect({ GetX() - 8, GetY() + 8, life / 2, 2 }, color);
				}
			}

			//ターゲット
			if (SStage->selected == this)
			{
				MIcon::ターゲット[(timer / 10) % 3]->DrawRotate({ GetX(), GetY() }, 1, 0);
			}
		}

		/**Stage右に表示する情報.*/
		void DrawInfo() override
		{
			namespace UI = UI_Unit;

			//画像&名前
			MSystem::フレーム[5].Draw(UI::R名前);
			MUnit::敵[st->種族][1]->DrawRotate(UI::P画像, 2, 0);
			MFont::ゴシック中.DrawShadow(UI::P名前, Color::White, Color::Gray, st->種族名);

			//説明文
			MSystem::フレーム[5].Draw(UI::R説明);
			MFont::ゴシック小.DrawShadow(UI::P説明, Color::White, Color::Gray, st->説明文);

			//性能

			IconType IconNo[7] =
			{
				IconType::レベル,
				IconType::ライフ,
				IconType::速度,
				IconType::マナ,
				IconType::防御,
				IconType::回避,
				IconType::回復
			};
			int Num[7] =
			{
				レベル,
				(int)残りHP,
				(int)(st->移動速度 * 10),
				スコア,
				防御力,
				(int)回避力,
				(int)再生力
			};

			for (int a = 0; a < 6; ++a)
			{
				if (Num[a] <= 0 && a > 3) continue;//防御と回避は0なら表示しない

				MSystem::フレーム[5].Draw(UI::R性能[a], { 128, 128, 255 });
				MIcon::UI[IconNo[a]].Draw(UI::P性能アイコン[a]);
				MFont::BMP白.DrawExtend(UI::P性能[a], 2, 2, Color::White, { std::setw(10), Num[a] });
			}
		}

		/**消滅判定.*/
		bool RemoveCheck() override
		{
			const int x = (int)GetX() / CHIP_SIZE;
			const int y = (int)GetY() / CHIP_SIZE;

			if (残りHP <= 0)
			{
				Dead();
			}
			else if (SStage->land.地形[x][y] == ChipType::畑)
			{
				//ゴール判定
				if (isBoss)
				{
					Witch::Main->Damage(ボスダメージ);
				}
				else
				{
					Witch::Main->Damage(1);
				}				
				isRemove = true;
			}

			if (isRemove)
			{
				SStage->ResetSelect(this);
				Remove();
			}

			return isRemove;
		}

		/**攻撃された時の処理.*/
		void Damaged(IShot* 衝突相手)
		{
			double ダメージ量 = 衝突相手->攻撃力;

			//属性効果判定
			if (衝突相手->デバフ効果 > 0 && !st->特殊耐性[衝突相手->st->デバフ種])
			{
				switch (衝突相手->st->デバフ種)
				{
				case DebuffType::鈍足: 鈍足付与(衝突相手); break;
				case DebuffType::麻痺: 麻痺付与(衝突相手); break;
				case DebuffType::吹飛: 吹飛付与(衝突相手); break;
				case DebuffType::防壊: 防壊付与(衝突相手); break;
				default:break;
				}
			}

			//特攻補正
			if (st->サブ種族 == 衝突相手->st->特攻種族)
			{
				ダメージ量 *= Witch::Main->弱点補正;
			}

			//防御補正
			ダメージ量 = std::max(ダメージ量 - 防御力, 1.0);

			残りHP -= ダメージ量;
		}

		void 麻痺付与(IShot* 衝突相手)
		{
			//判定
			if (!Rand::Coin(衝突相手->デバフ率)){ return; }

			//付与処理、残り時間を上回る場合のみ上書き
			麻痺時間 = std::max(衝突相手->デバフ効果, 麻痺時間);
		}
		void 鈍足付与(IShot* 衝突相手)
		{
			if (鈍足時間 <= 0){ 鈍足率 = 1.0; }

			//付与処理
			鈍足率 = std::max(衝突相手->デバフ率, 鈍足率);
			鈍足時間 = std::max(衝突相手->デバフ効果, 鈍足時間);
		}
		void 吹飛付与(IShot* 衝突相手)
		{
			//付与処理
			const double 吹き飛び距離 = 衝突相手->デバフ効果;

			吹き飛びX += std::cos(衝突相手->GetAngle()) * 吹き飛び距離;
			吹き飛びY += std::sin(衝突相手->GetAngle()) * 吹き飛び距離;
		}
		void 防壊付与(IShot* 衝突相手)
		{
			//付与処理
			防御力 = std::max(0, 防御力 - 衝突相手->デバフ効果);
		}

	};

	class Enemy : public IEnemy
	{
	public:
		Rect shape;
		SpNull sprite;

		Enemy(double X座標, double Y座標, EnemyType 敵種類, int Lv, bool isBoss) :
			IEnemy(shape, sprite, &EnemyDataS[敵種類], Lv, isBoss),
			shape((X座標 + 0.5)*CHIP_SIZE, (Y座標 + 0.5)*CHIP_SIZE, 判定大きさ / 2, 判定大きさ / 2, 判定大きさ / 2, 判定大きさ / 2)
		{
			if (isBoss)
			{
				shape.SetZoom(2, 2);
			}
		}

		/** 更新処理.*/
		/**@todo 飛行タイプは移動方法変えるかも？*/
		void Act() override
		{
			//飛行能力発動
			if (st->is離陸 && 残りHP < 最大HP / 2 && 移動種 != MoveType::空)
			{
				移動種 = MoveType::空;
			}

			//シャーマン/召喚/10秒に1回/ボスは1秒に1回
			if (st->種族 == EnemyType::シャーマン && timer % 60 + 540 * !isBoss == 0)
			{
				auto enemy = new Enemy(GetX(), GetY(), EnemyType::ゼリー, レベル,false);
				double r = Rand::Get(PAI);
				enemy->最大HP /= 16;
				enemy->残りHP /= 16;
				enemy->スコア = 0;
				enemy->再生力 = 0;
				enemy->麻痺時間 = 120;
				enemy->吹き飛びX = std::sin(PAI) * 16 * (1 + isBoss);
				enemy->吹き飛びY = std::cos(PAI) * 16 * (1 + isBoss);

				SStage->Add(enemy);
			}

			//再生力
			if (再生力 > 0 && 残りHP > 0 && 鈍足時間 <= 0 && 麻痺時間 <= 0)
			{
				残りHP += 再生力;
			}

			//スリップダメージ効果
			if (Witch::Main->is継続ダメージ)
			{
				if (鈍足時間)
				{
					残りHP -= 残りHP / 200;
				}
				if (麻痺時間)
				{
					残りHP -= 残りHP / 200;
				}
			}

			//移動
			Walk();
		}

		/** 移動処理.*/
		void Walk()
		{
			double speed = st->移動速度;
			const int x = (int)(GetX() / CHIP_SIZE);
			const int y = (int)(GetY() / CHIP_SIZE);

			//方向を更新
			方向更新();

			if (isBoss){ speed *= 0.66; }

			//異常補正
			if (麻痺時間 > 0)
			{
				speed = 0;
				--麻痺時間;
			}

			if (鈍足時間 > 0)
			{
				speed = speed * 鈍足率;
				--鈍足時間;
			}

			//斜め移動補正
			if (方向 % 2 == 0) speed *= 0.7;

			//ピンチで加速
			if (st->is加速 && 残りHP < 最大HP / 2)
			{
				speed *= 1.5;
			}

			double mx = (方向 % 3 - 1) * speed;
			double my = (方向 / 3 - 1) * speed;

			//吹き飛び処理
			mx += 吹き飛びX / 8;
			吹き飛びX -= 吹き飛びX / 8;
			my += 吹き飛びY / 8;
			吹き飛びY -= 吹き飛びY / 8;

			地形処理(mx, my);
			Move(mx, my);
			地形衝突();
		}

		/**死亡時、基本処理.*/
		void Dead() override
		{
			//分裂
			if (st->種族 == EnemyType::ゼリー王)
			{
				for (int a = 0; a < 4; ++a)
				{
					auto enemy = new Enemy(GetX(), GetY(), EnemyType::ゼリー, レベル, isBoss);
					double r = Rand::Get(PAI);
					enemy->最大HP /= 4;
					enemy->残りHP /= 4;
					enemy->スコア /= 4;
					enemy->麻痺時間 = 120;
					enemy->吹き飛びX = std::sin(PAI) * 16 * (1 + isBoss);
					enemy->吹き飛びY = std::cos(PAI) * 16 * (1 + isBoss);

					SStage->Add(enemy);
				}
			}

			//MP&SP&スコア増
			if (TDSystem::isカップル)
			{
				Witch::Main->Mp += スコア*0.07;
				Witch::Sub->Mp += スコア*0.03;
			}
			else
			{
				Witch::Main->Mp += スコア *0.1;
			}

			Witch::Main->AddSp(st->スコア);

			//ダメージに応じてスコアは5%まで低下
			SStage->score += int(スコア * std::max(1.0, 10 - 0.5*Witch::被ダメージ));

			MSound::撃破.Play();

			isRemove = true;
		}
	};
}