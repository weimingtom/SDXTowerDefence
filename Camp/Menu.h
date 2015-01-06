﻿//Copyright © 2014 (´･@･)
//[License]GNU Affero General Public License, version 3
//[Contact]http://tacoika.blog87.fc2.com/
#pragma once
#include "Mission/Layer.h"
#include "Mission/Object.h"
#include "IMenu.h"

namespace SDX_TD
{
	using namespace SDX;

	/**メニュー項目を配置.*/
	class Menu : public IMenu
	{
	private:
		Layer<IObject> backEffectS;
		Layer<IObject> midEffectS;
		Layer<IObject> frontEffectS;
	public:

		int timer = 0;

		Camera camera;

		Menu() :
			camera({ 400, 300 }, 1)
		{
			Init();
		}

		void Init()
		{
			SMenu = this;
		}

		/**毎フレーム実行される更新処理.*/
		void Update() override
		{
			SMenu = this;
			++timer;

			//レイヤー処理
			backEffectS.Update();
			midEffectS.Update();
			frontEffectS.Update();

			//消滅処理
			backEffectS.ExeRemove();
			midEffectS.ExeRemove();
			frontEffectS.ExeRemove();
		}

		/**画面の描画.*/
		void Draw() override
		{
			SMenu = this;

			backEffectS.Draw();

			midEffectS.Draw();

			frontEffectS.Draw();
		}

		/**エフェクト等を追加.*/
		void Add(IObject* 追加するオブジェクト, int 待機時間 = 0) override
		{
			midEffectS.Add(追加するオブジェクト, 待機時間);
		}
		/**前景オブジェクトを追加.*/
		void AddFront(IObject* 追加するオブジェクト, int 待機時間 = 0) override
		{
			frontEffectS.Add(追加するオブジェクト, 待機時間);
		}
		/**背景オブジェクトを追加.*/
		void AddBack(IObject* 追加するオブジェクト, int 待機時間 = 0) override
		{
			backEffectS.Add(追加するオブジェクト, 待機時間);
		}
	};
}