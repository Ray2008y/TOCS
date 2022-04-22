#include <iostream>
#include <easy2d/easy2d.h>
#include "GameScene.h"
using namespace easy2d;
Scene* scene;
Scene* game;
bool Start() {
	auto gs = gcnew GameScene();
	SceneManager::enter(gs);
	return true;
}
void EnterScene() {
	scene = gcnew Scene;//新建场景
	auto background = gcnew Sprite(L"pic//B.png");//新建背景
	background->setPos(Window::getSize() / 2);//生成位置
	background->setScale(1.0f, 1.0f);
	scene->addChild(background);//将背景添加到场景中
	auto player = gcnew Sprite(L"pic//player.png");//新建人物
	player->setPos(Window::getWidth() / 2 - 15, Window::getHeight() / 2 - 50);//生成位置
	player->setScale(0.3f, 0.3f);
	scene->addChild(player);//将人物添加到场景中
	SceneManager::enter(scene);//进入场景
}
void button() {
	auto startbutton = gcnew Button;//开始按钮
	startbutton->setNormal(gcnew Sprite(L"pic//start1.png"));//常态
	startbutton->setSelected(gcnew Sprite(L"pic//start2.png"));//选择时
	startbutton->setPos(Window::getWidth() / 2, Window::getHeight() - 80);//生成位置
	auto Pcallback = []() {
		Start();
	};
	startbutton->setClickFunc(Pcallback);//设置回调函数
	scene->addChild(startbutton);//将按钮加入场景
}
void caption() {
	auto font = Font(L"Aa未来黑", 50, Font::Weight::Bold, false);
	auto text = gcnew Text(L"卖 炭 翁");
	scene->addChild(text);
	text->setFont(font);
	text->setAnchor(0.5f, 0.5f);
	text->setPos(Window::getWidth() / 2, Window::getHeight() / 3 - 30);
}
int main() {
	Logger::showConsole(false);//隐藏控制台
	if (Game::init(L"GAME", 960, 720)) {
		//std::cout << " Initialize the success!" << std::endl;
		Node::setDefaultAnchor(0.5f, 0.5f);
		EnterScene();
		caption();
		button();

		//以下是游戏代码

		//以上是游戏代码
		Game::start();
	}
	Game::destroy();
	return 0;
}
