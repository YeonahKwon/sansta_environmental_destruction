#include <bangtal>
using namespace bangtal;

int main()
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	auto santa = 0;
	auto cloth = 0;
	auto ride = 0;
	auto mask = 0;

	auto makemask = 0;

	//1. 장면 생성
	ScenePtr scene0 = Scene::create("산타네 집", "images/산타방1.jpg");
	ScenePtr scene0_1 = Scene::create("산타네 집", "images/산타방2.jpg");
	ScenePtr scene1 = Scene::create("창고", "images/창고.jpg");
	ScenePtr scene2 = Scene::create("엘프 학교", "images/작업실1.png");
	ScenePtr scene2_1 = Scene::create("엘프 학교", "images/작업실2.jpg");
	ScenePtr scene2_2 = Scene::create("엘프 학교", "images/작업실3.jpg");
	ScenePtr scene2_3 = Scene::create("엘프 학교", "images/작업실4.jpg");
	ScenePtr scene2_4 = Scene::create("엘프 학교", "images/작업실5.jpg");
	ScenePtr scene2_5 = Scene::create("엘프 학교", "images/작업실6.jpg");
	ScenePtr scene3 = Scene::create("썰매 센터", "images/루돌프배경.png");
	ScenePtr scene4 = Scene::create("MERRY CHRISTMAS", "images/엔딩_마스크.png");
	ScenePtr scene5 = Scene::create("산타마을", "images/마을1.jpg");
	ScenePtr scene5_1 = Scene::create("산타마을", "images/마을2.jpg");
	ScenePtr scene5_2 = Scene::create("산타마을", "images/마을3.jpg");
	ScenePtr scene5_3 = Scene::create("산타마을", "images/마을4.jpg");

	auto sound = Sound::create("images/Jingle Bells.mp3");
	sound->play();

	//시작 종료 버튼 생성

	auto intro = Object::create("images/알림_시작.png", scene0, 170, 100);
	intro->setScale(0.17f);
	auto startButton = Object::create("images/시작버튼.png", scene0, 550, 50);
	startButton->setScale(0.2f);
	//auto endButton = Object::create("images/종료버튼.png", scene0, 680, 20);
//	endButton->setScale(0.3f);

	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		startButton->hide();
		//endButton->hide();
		intro->hide();
		scene0->enter();
		
		//산타방

		//창고 아이콘
		auto room = Object::create("images/창고버튼.png", scene0, 950, 610);
		room->setScale(0.7f);
		room->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (mask == 1)
			{
				showMessage("마스크에 필요한 재료를 다 찾았다!\n이제 마스크는 문제없다!");
			}
			else scene1->enter();
			return true;
		});

		auto room1 = Object::create("images/창고버튼.png", scene0_1, 950, 610);
		room1->setScale(0.7f);
		room1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (mask == 1)
			{
				showMessage("마스크에 필요한 재료를 다 찾았다!\n이제 마스크는 문제없다!");
			}
			else scene1->enter();
			return true;
			});
		auto room2 = Object::create("images/거실버튼.png", scene1, 1050, 610);
		room2->setScale(0.7f);
		room2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if(cloth==0) scene0->enter();
			else if (cloth == 1) scene0_1->enter();
			return true;
			});


		//지도 아이콘
		auto map0 = Object::create("images/지도아이콘.png", scene0, 1150, 610);
		map0->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (santa == 0) { scene5->enter(); return true; }
			else if (santa == 1) { scene5_1->enter(); return true; }
			else if (santa == 2) { scene5_2->enter(); return true; }
			else if (santa == 3) { scene5_3->enter(); return true; }
			});
		return true;
		});

	/*endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();

		return true;
		});*/


		//전기에너지게임///////////////////////////////
	auto make_electro = 0;
	auto roo1 = Object::create("images/루돌프1.png", scene3, 450, 0);
	//roo1->setScale(0.7f);
	auto roo2 = Object::create("images/루돌프2.png", scene3, 450, 0, false);
	//roo2->setScale(0.7f);

	//지도아이콘 

	auto map0_1 = Object::create("images/지도아이콘.png", scene0_1, 1150, 610);
	map0_1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (santa == 0) { scene5->enter(); return true; }
		else if (santa == 1) { scene5_1->enter(); return true; }
		else if (santa == 2) { scene5_2->enter(); return true; }
		else if (santa == 3) { scene5_3->enter(); return true; }
	//	});
	return true;
		});
		auto map2 = Object::create("images/지도아이콘.png", scene2, 1150, 610);
		map2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (santa == 0) { scene5->enter(); return true; }
			else if (santa == 1) { scene5_1->enter(); return true; }
			else if (santa == 2) { scene5_2->enter(); return true; }
			else if (santa == 3) { scene5_3->enter(); return true; }
		//	});
		return true;
		});
		auto map2_5 = Object::create("images/지도아이콘.png", scene2_5, 1150, 610);
		map2_5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (santa == 0) { scene5->enter(); return true; }
			else if (santa == 1) { scene5_1->enter(); return true; }
			else if (santa == 2) { scene5_2->enter(); return true; }
			else if (santa == 3) { scene5_3->enter(); return true; }
		//	});
		return true;
		});
		auto map3 = Object::create("images/지도아이콘.png", scene3, 1150, 610);
		map3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (santa == 0) { scene5->enter(); return true; }
			else if (santa == 1) { scene5_1->enter(); return true; }
			else if (santa == 2) { scene5_2->enter(); return true; }
			else if (santa == 3) { scene5_3->enter(); return true; }
			//});
		return true;
		});


	//팻말생성
	if (santa == 0) {
		auto h_go = Object::create("images/팻말_출발.png", scene5, 170, 360);
		h_go->setScale(0.1f);
		h_go->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			showMessage("출발 준비가 아직이다!");
			return true;
			});
		auto c_go = Object::create("images/팻말_산타집.png", scene5, 1030, 360);
		c_go->setScale(0.1f);
		c_go->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene0->enter();
			return true;
			});
		auto s_go = Object::create("images/팻말_썰매.png", scene5, 240, 1);
		s_go->setScale(0.1f);
		s_go->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene3->enter();
			return true;
			});
		auto m_go = Object::create("images/팻말_학교.png", scene5, 1000, 1);
		m_go->setScale(0.1f);
		m_go->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene2->enter();
			return true;
			});
	}
	//else if (santa == 1) {
		auto h_go1 = Object::create("images/팻말_출발.png", scene5_1, 170, 360);
		h_go1->setScale(0.1f);
		h_go1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			showMessage("출발 준비가 아직이다!");
			return true;
			});
		auto c_go1 = Object::create("images/팻말_산타집.png", scene5_1, 1030, 360);
		c_go1->setScale(0.1f);
		c_go1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (cloth == 0) scene0->enter();
			else if (cloth == 1) scene0_1->enter();
			return true;
			});
		auto s_go1 = Object::create("images/팻말_썰매.png", scene5_1, 240, 1);
		s_go1->setScale(0.1f);
		s_go1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (ride == 1) showMessage("썰매는 준비가 다 되었다!");
			else if (ride == 0) scene3->enter();
			return true;
			});
		auto m_go1 = Object::create("images/팻말_학교.png", scene5_1, 1000, 1);
		m_go1->setScale(0.1f);
		m_go1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (cloth == 1) showMessage("산타복은 이미 만들었다!");
			else if (cloth == 0) scene2->enter();
			return true;
			});
	//}

	//else if (santa == 2) {
		auto h_go2 = Object::create("images/팻말_출발.png", scene5_2, 170, 360);
		h_go2->setScale(0.1f);
		h_go2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			showMessage("출발 준비가 아직이다!");
			return true;
			});
		auto c_go2 = Object::create("images/팻말_산타집.png", scene5_2, 1030, 360);
		c_go2->setScale(0.1f);
		c_go2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (cloth == 0) scene0->enter();
			else if (cloth == 1) scene0_1->enter();
			return true;
			});
		auto s_go2 = Object::create("images/팻말_썰매.png", scene5_2, 240, 1);
		s_go2->setScale(0.1f);
		s_go2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (ride == 1) showMessage("썰매는 준비가 다 되었다!");
			else if (ride == 0) scene3->enter();
			return true;
			});
		auto m_go2 = Object::create("images/팻말_학교.png", scene5_2, 1000, 1);
		m_go2->setScale(0.1f);
		m_go2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (cloth == 1) showMessage("산타복은 이미 만들었다!");
			else if (cloth == 0) scene2->enter();
			return true;
			});
	//}
	//else if (santa == 3) {
		auto h_go3 = Object::create("images/팻말_출발.png", scene5_3, 170, 360);
		h_go3->setScale(0.1f);
		h_go3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene4->enter();
			return true;
			});
		auto c_go3 = Object::create("images/팻말_산타집.png", scene5_3, 1030, 360);
		c_go3->setScale(0.1f);
		c_go3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (cloth == 0) scene0->enter();
			else if (cloth == 1) scene0_1->enter();
			return true;
			});
		auto s_go3 = Object::create("images/팻말_썰매.png", scene5_3, 240, 1);
		s_go3->setScale(0.1f);
		s_go3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			showMessage("썰매는 준비가 다 되었다!");
			return true;
			});
		auto m_go3 = Object::create("images/팻말_학교.png", scene5_3, 1000, 1);
		m_go3->setScale(0.1f);
		m_go3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			showMessage("산타복은 이미 만들었다!");
			return true;
			});
	//}

	//마스크만들기게임/////////////////////////////////////////////////

			auto scissor = Object::create("images/마스크_가위.png", scene1, 100, 20);
		scissor->setScale(0.2f);
		auto roap = Object::create("images/마스크_끈.png", scene1, 500, 220);
		roap->setScale(0.2f);
		auto niddle = Object::create("images/마스크_바늘.png", scene1, 50, 280);
		niddle->setScale(0.2f);
		auto paper = Object::create("images/마스크_천.png", scene1, 800, 110);
		paper->setScale(0.2f);

	auto maskgame = Object::create("images/알림_마스크.png", scene1, 170, 100);
	maskgame->setScale(0.17f);
	auto maskstart = Object::create("images/시작버튼.png", scene1, 550, 50);
	maskstart->setScale(0.2f);
	
	 
	maskstart->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		maskstart->hide();
		maskgame->hide();

		return true;
		});

			scissor->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				scissor->hide();
				makemask= makemask+1;
				if (makemask == 4)
				{
					santa = santa + 1;
					mask = 1;
					showMessage("마스크에 필요한 재료를 다 찾았다!\n이제 마스크는 문제없다!");
				}
				return true;
				});
			roap->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				roap->hide();
				makemask=makemask+1;
				if (makemask == 4)
				{
					santa = santa + 1;
					mask = 1;
					showMessage("마스크에 필요한 재료를 다 찾았다!\n이제 마스크는 문제없다!");
				}
				return true;
				});
			niddle->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				niddle->hide();
				makemask =makemask+1;
				if (makemask == 4)
				{
					santa = santa + 1;
					mask = 1;
					showMessage("마스크에 필요한 재료를 다 찾았다!\n이제 마스크는 문제없다!");
				}
				return true;
				});
			paper->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				paper->hide();
				makemask=makemask+1;
				if (makemask == 4)
				{
					santa = santa + 1;
					mask = 1;
					showMessage("마스크에 필요한 재료를 다 찾았다!\n이제 마스크는 문제없다!");
				}
				return true;
				});
			

///////////////////전기에너지게임///////////////
			auto car1 = Object::create("images/썰매1.png", scene3, 20, 10);
			car1->setScale(1.1f);
			auto car2 = Object::create("images/썰매2.png", scene3, 20, 10,false);
			car2->setScale(1.1f);
			auto car3 = Object::create("images/썰매3.png", scene3, 20, 10,false);
			car3->setScale(1.1f);
			auto car4 = Object::create("images/썰매4.png", scene3, 20, 10, false);
			car4->setScale(1.1f);

			auto electrogame = Object::create("images/알림_루돌프.png", scene3, 110, 80);
			electrogame->setScale(0.7f);
			auto electrostart = Object::create("images/시작버튼.png", scene3, 550, 110);
			electrostart->setScale(0.2f);

			electrostart->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				electrostart->hide();
				electrogame->hide();

				auto roo_button = Object::create("images/루돌프버튼.png", scene3, 550, 0);
				roo_button->setScale(0.7f);

				roo_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					make_electro = make_electro + 1;
					if (make_electro % 2 == 0) { roo1->hide(); roo2->show(); }
					else { roo1->show(); roo2->hide(); }

					if (make_electro > 30)
					{
						showMessage("썰매가 완전히 충전되었다!");
					}
					else if (make_electro == 30)
					{
						car4->show();
						car3->hide();
						showMessage("썰매가 완전히 충전되었다!");
						ride = 1;
						santa = santa + 1;
					}
					else if (make_electro == 20)
					{
						car3->show();
						car2->hide();
					}
					else if (make_electro == 10)
					{
						car2->show();
						car1->hide();
					}

					return true;
					});


				return true;
				});
				


	//옷만들기게임///////////////////////

	auto makecloth = 0;

	auto count = 0;

	auto playButton = Object::create("images/엘프버튼.png", scene2, 900, 10, false);
	playButton->setScale(0.17f);

	auto clothgame = Object::create("images/알림_산타옷.png", scene2, 170, 100);
	clothgame->setScale(0.17f);
	auto clothstart = Object::create("images/시작버튼.png", scene2, 550, 110);
	clothstart->setScale(0.2f);


	auto timer = Timer::create(10.f);



	clothstart->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		clothstart->hide();
		clothgame->hide();
		playButton->show();
		//dang4->hide();

		showTimer(timer);
		timer->setOnTimerCallback([&](TimerPtr)->bool {
			scene2->enter();
			showMessage("산타옷 제작 실습 재수강 확정!");
			clothstart->show();
			timer->stop();
			playButton->hide();
			return true;
			});

		makecloth = 0;
		timer->set(10.f);
		timer->start();
		return true;
		});

	playButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2_1->enter();
		auto playButton1 = Object::create("images/엘프버튼.png", scene2_1, 200, 410);
		playButton1->setScale(0.15f);
		playButton1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene2_2->enter();
			auto playButton2 = Object::create("images/엘프버튼.png", scene2_2, 60, -10);
			playButton2->setScale(0.13f);
			playButton2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				scene2_3->enter();
				auto playButton3 = Object::create("images/엘프버튼.png", scene2_3, 1100, 510);
				playButton3->setScale(0.1f);
				playButton3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					scene2_4->enter();
					auto playButton4 = Object::create("images/엘프버튼.png", scene2_4, 900, 1);
					playButton4->setScale(0.08f);
					playButton4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
						scene2_5->enter();
						auto playButton5 = Object::create("images/엘프버튼.png", scene2_5, 700, 600);
						playButton5->setScale(0.06f);
						playButton5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
							showMessage("산타옷 제작 실습 A+!");
							cloth = 1;
							count = count + 1;
							if(count==1) santa = santa + 1;
							timer->stop();
							return true;
							});
						return true;
					});
				return true;
				});
			return true;
			});
		return true;
		});
		return true;
		});
		
	////////////////////////////////

	//2. 게임 시작
	startGame(scene0);
	return 0;
}