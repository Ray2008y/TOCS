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
	scene = gcnew Scene;//�½�����
	auto background = gcnew Sprite(L"pic//B.png");//�½�����
	background->setPos(Window::getSize() / 2);//����λ��
	background->setScale(1.0f, 1.0f);
	scene->addChild(background);//��������ӵ�������
	auto player = gcnew Sprite(L"pic//player.png");//�½�����
	player->setPos(Window::getWidth() / 2 - 15, Window::getHeight() / 2 - 50);//����λ��
	player->setScale(0.3f, 0.3f);
	scene->addChild(player);//��������ӵ�������
	SceneManager::enter(scene);//���볡��
}
void button() {
	auto startbutton = gcnew Button;//��ʼ��ť
	startbutton->setNormal(gcnew Sprite(L"pic//start1.png"));//��̬
	startbutton->setSelected(gcnew Sprite(L"pic//start2.png"));//ѡ��ʱ
	startbutton->setPos(Window::getWidth() / 2, Window::getHeight() - 80);//����λ��
	auto Pcallback = []() {
		Start();
	};
	startbutton->setClickFunc(Pcallback);//���ûص�����
	scene->addChild(startbutton);//����ť���볡��
}
void caption() {
	auto font = Font(L"Aaδ����", 50, Font::Weight::Bold, false);
	auto text = gcnew Text(L"�� ̿ ��");
	scene->addChild(text);
	text->setFont(font);
	text->setAnchor(0.5f, 0.5f);
	text->setPos(Window::getWidth() / 2, Window::getHeight() / 3 - 30);
}
int main() {
	Logger::showConsole(false);//���ؿ���̨
	if (Game::init(L"GAME", 960, 720)) {
		//std::cout << " Initialize the success!" << std::endl;
		Node::setDefaultAnchor(0.5f, 0.5f);
		EnterScene();
		caption();
		button();

		//��������Ϸ����

		//��������Ϸ����
		Game::start();
	}
	Game::destroy();
	return 0;
}
