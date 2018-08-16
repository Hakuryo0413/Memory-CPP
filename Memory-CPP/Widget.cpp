#include "stdafx.h"
#include "Widget.h"

Widget::Widget()
	: selected(false)
{
}

Widget::~Widget()
{
}

bool Widget::isSelected() const
{
	return selected;
}

void Widget::select()
{
	selected = true;
}

void Widget::deselect()
{
	selected = false;
}
