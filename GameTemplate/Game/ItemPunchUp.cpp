#include "stdafx.h"
#include "ItemPunchUp.h"
#include "Item.h"
#include "Player.h"

bool ItemPunchUp::Start()
{
	m_modelRender.Init("Assets/modelData/item/heart.tkm");
	m_modelRender.SetScale({ 0.3f,0.3f,0.3f });
	m_modelRender.Update();
	return true;
}

void ItemPunchUp::Update()
{
	m_item->GetItem(m_position);
	PunchUpGetAndUse();
	m_modelRender.Update();
}

void ItemPunchUp::PunchUpGetAndUse()
{
	//アイテムをゲットした判定
	if (m_item->GetItem(m_position) == true) {
		//GetItem関数の戻り値を代入
		getFlag = m_item->GetItem(m_position);
		m_item->GetItemCount(getFlag, count);
		SetCount(m_item->GetItemCount(getFlag, count));
		m_item->PlayEffectandSE();
		DeleteGO(this);
	}
	//アイテムを使った判定
	if (g_pad[0]->IsTrigger(enButtonB) && m_player->GetDashTimer() <= 0.0f)
	{
		if (useFlag == true) {
			m_item->ItemUse(useFlag, count);
			SetCount(m_item->ItemUse(getFlag, count));
		}
	}
}

void ItemPunchUp::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}