// This file is autogenerated. See look at the .lzz files in the src/ directory for a more human-friendly version
// example.hh
//

#ifndef LZZ_example_hh
#define LZZ_example_hh
#include <iostream>
#include <SDL3/SDL.h>
#include <cmath>
#include "sdl-stb-font/sdlStbFont.h"
#define VGUI_DO_DELTA_DRAWING 1

// Include the header
#include "vgui.h"
#include "sdl_vgui_context.h"

// Include the implementation
#define VECGUI_IMPL 1
#include "vgui.h"
#include "sdl_vgui_context.h"

#define LZZ_INLINE inline
void readFileRaw (std::string const & fullPath, std::string & output);
class TestCallback : public Vgui_EventCallbackI
{
public:
  void onMouseEvent (Vgui_Widget * W, VGUI_COORD mouseX, VGUI_COORD mouseY, uint8_t buttonMask, bool isDown);
};
int cleanup (SDL_Vgui_Context * vTestContext);
int main (int argc, char * * argv);
#undef LZZ_INLINE
#endif

////////////////////////////////////////////////////////////////////////

#ifdef VECGUI_IMPL
#ifndef VECGUI_IMPL_DOUBLE_GUARD_example
#define VECGUI_IMPL_DOUBLE_GUARD_example
// example.cpp
//

#define SDL_STB_FONT_IMPL
#include "sdl-stb-font/sdlStbFont.h"

#include <fstream>

#define LZZ_INLINE inline
void readFileRaw (std::string const & fullPath, std::string & output)
                                                                      {
	std::ifstream fs(fullPath.c_str(), std::ios::in | std::ios::binary);
	
	if (!fs.is_open()) {
		std::cout << "readFileRaw: " << fullPath << " -- " << "WARNING: Could not open file." << std::endl;
		return;
		}
	else {
		std::cout << "Opened! " << fullPath << std::endl;
		}
				
	fs.seekg (0, std::ios::end);
	const size_t LEN = fs.tellg();
	fs.seekg (0, std::ios::beg);
	
	output.resize(LEN);
	fs.read(&output[0], LEN);
	fs.close();
	}
void TestCallback::onMouseEvent (Vgui_Widget * W, VGUI_COORD mouseX, VGUI_COORD mouseY, uint8_t buttonMask, bool isDown)
                                                                                                                  {
		if (isDown) {
			std::cout << "MOUSE_DOWN " << W->tag << "(" << ((void*)W) << ")! Callback called!" << std::endl;
			}
		else {
			std::cout << "MOUSE_UP " << W->tag << "(" << ((void*)W) << ")! Callback called!" << std::endl;
			}
		}
int cleanup (SDL_Vgui_Context * vTestContext)
                                             {
	delete vTestContext->mSkin;
	//delete vTestContext->mCanvas;
	//vTestContext->mCanvas = NULL;
	delete vTestContext;
	Vgui_Cleanup();
	//std::cout << Vgui_StyleStuff::primative::allocCount << std::endl;
	return 1;
	}
int main (int argc, char * * argv)
                                  {
	int windowWidth = 600;
	int windowHeight = 400;

	SDL_Init(0);
	SDL_Window * mWindow = SDL_CreateWindow("Example Test", windowWidth, windowHeight, SDL_WINDOW_RESIZABLE);
	
	SDL_Renderer * mSdlRenderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(mWindow));
	
	
	// Create an SDL render and tell it about the renderer
	SDL_Vgui_Context * vTestContext = new SDL_Vgui_Context();
	vTestContext->bind();
	vTestContext->mSkin = new Vgui_DefaultSkin(); 
	
	vTestContext->mRenderer = mSdlRenderer;
	
	// Font
	sdl_stb_font_cache * gFont = new sdl_stb_font_cache();
	vTestContext->scalef = 1.0;

	int faceSize = 24 * vTestContext->scalef;
	gFont->faceSize = faceSize;
	gFont->bindRenderer(mSdlRenderer);
		
	std::string notoSans;
	std::string notoSansCJK;
	readFileRaw("sdlStbFont/fonts/NotoSans-Regular.ttf", notoSans);
	readFileRaw("sdlStbFont/fonts/NotoSansCJKjp-Regular.otf", notoSansCJK);
	
	gFont->loadFont(notoSans.c_str());
	gFont->addFont(notoSansCJK.c_str());
	
	//FC_LoadFont (gFont, mSdlRenderer, "fonts/Spoqa Han Sans Regular.ttf", faceSize, FC_MakeColor(0,0,0,255), TTF_STYLE_NORMAL);
	
	vTestContext->gFont = gFont;

	
	vTestContext->mCanvas = (new Vgui_Frame())->setPos(10,10)
						->setSize(600,300)
						->setDimModeBoth(Vgui_DimMode::VGUI_DIM_COORDINATE) // Must be set when size is manually set!
						->setColorF(0.8,0.8,0.8,1.0)
						//->setInnerPadding(1)
						->setText(sttfont_formatted_text() << sttfont_format::red << "Frame " << sttfont_format::green << "Label")
						;
	
	
	vTestContext->mCanvas->setStyle(Vgui_ContextI::aContext->mSkin->LabeledFrame);
		
	// Make fit window
	//vTestContext->mCanvas->setSize(95,95)->setDimModeBoth(Vgui_DimMode::VGUI_DIM_PERCENT);

				
	vTestContext->mCanvas->addChild(
				(new Vgui_Button())->setPos(0,0)
						->setColorF(0.0,1.0,0.4,1.0)
						->setInnerPaddingAll(0)
				//		->setAlignmentH(VGUI_CENTER)
				//		->setAlignmentV(VGUI_BOTTOM)
						->setTag("button")
				);

vTestContext->mCanvas->yScrollMax = 800;
vTestContext->mCanvas->xScrollMax = 400;

TestCallback TC;
vTestContext->mCanvas->mEventCallback = &TC;


	auto B = vTestContext->fetchElement("button");
	//B->widthIsPercentage = true;
	//B->yIsPercentage = true;
	//B->xIsPercentage = true;
	//B->y = 25;
	//B->x = -25;
	B->text.assign("demoTextfffff");

//	B->addChild(
//		//(new Vgui_Text("Buttonzzfasdfasdfasdg"))
//		);

VGUI_STRING ipso =  "\nIn publishing and graphic design, lorem\nipsum is a placeholder text commonly used\nto demonstrate the visual form of a\ndocument without relying on meaningful content.";
for (int i = 0; i < 5; ++i) {
	ipso += ipso;
	}
	ipso = "";


	vTestContext->mCanvas->addChild ( (new Vgui_Text("Hello asdfasfd\nasdfsdaf asdfsda texxxxxxxxxxaast" + ipso))
						->setTag("text")
						->setAlignmentH(Vgui_Alignment::VGUI_CENTER)
						->setAlignmentV(Vgui_Alignment::VGUI_CENTER)
					);
					
	vTestContext->mCanvas->addChild ( (new Vgui_Button ("Ok"))
						->setTag("btext")
						->setAlignmentV(Vgui_Alignment::VGUI_BOTTOM)
						->setAlignmentH(Vgui_Alignment::VGUI_CENTER)
					);

	
	auto B2 = vTestContext->fetchElement("btext");
	B2->widthMode  = Vgui_DimMode::VGUI_DIM_TEXT;
	B2->heightMode = Vgui_DimMode::VGUI_DIM_TEXT;

	vTestContext->mCanvas->addChild ( (new Vgui_Text("btext"))
						->setAlignmentV(Vgui_Alignment::VGUI_BOTTOM)
					);
					
					
	vTestContext->mCanvas->addChild ( (new Vgui_TextEdit("Test String"))
						->setTag("btextedit")
					);
	auto BTE = vTestContext->fetchElement("btextedit");
	BTE->y = 1;
	BTE->ys = 1;
	BTE->heightMode = Vgui_DimMode::VGUI_DIM_TEXT_ROWS;
	BTE->yPosMode = Vgui_PosMode::VGUI_POS_TEXT_ROWS;
	BTE->setText("Demo Text");
	
	vTestContext->mCanvas->addChild ( (new Vgui_TextEdit("Test String"))
						->setTag("btextedit2")
					);
	BTE = vTestContext->fetchElement("btextedit2");
	BTE->y = 2;
	BTE->ys = 1;
	BTE->heightMode = Vgui_DimMode::VGUI_DIM_TEXT_ROWS;
	BTE->yPosMode = Vgui_PosMode::VGUI_POS_TEXT_ROWS;
	//BTE->setText("Demo Text2");
		BTE->setText(sttfont_formatted_text() << sttfont_format::red << "Demo " << sttfont_format::green << "Text2");
	
	
	vTestContext->mCanvas->addChild ( (new Vgui_MultilineText())
						->setTag("mltext")
					);
	Vgui_MultilineText * BMT = (Vgui_MultilineText*) vTestContext->fetchElement("mltext");
	BMT->y = 3;
	BMT->ys = 16;
	BMT->heightMode = Vgui_DimMode::VGUI_DIM_TEXT_ROWS;
	//BMT->xs = 80;
	//BMT->widthMode = Vgui_DimMode::VGUI_DIM_COORDINATE;
	BMT->yPosMode = Vgui_PosMode::VGUI_POS_TEXT_ROWS;
	BMT->setText(u8"01234\n56789\n\t\ncatnip\npenispenis\nexample\n\n你好γ εια σας Привет 여보세요 こんにちは \n	\n    Euro Symbol: €.\n    Greek: Μπορώ να φάω σπασμένα γυαλιά χωρίς να πάθω τίποτα.\n    Íslenska / Icelandic: Ég get etið gler án þess að meiða mig.\n    Polish: Mogę jeść szkło, i mi nie szkodzi.\n    Romanian: Pot să mănânc sticlă și ea nu mă rănește.\n    Ukrainian: Я можу їсти шкло, й воно мені не пошкодить.\n    Armenian: Կրնամ ապակի ուտել և ինծի անհանգիստ չըներ։\n    Georgian: მინას ვჭამ და არა მტკივა.\n    Hindi: मैं काँच खा सकता हूँ, मुझे उस से कोई पीडा नहीं होती.\n    Hebrew(2): אני יכול לאכול זכוכית וזה לא מזיק לי.\n    Yiddish(2): איך קען עסן גלאָז און עס טוט מיר נישט װײ.\n    Arabic(2): أنا قادر على أكل الزجاج و هذا لا يؤلمني.\n    Japanese: latintext私はガラスを食べられます。それは私を傷つけません。\n    asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf\n    Thai: ฉันกินกระจกได้ แต่มันไม่ทำให้ฉันเจ็บ)");
    
   // BMT->setText("01234\n56789\n\t\ncatnip\npenispenis\nexample" );
    //std::vector<sttfont_formatted_text> sampleBroken;
    //BMT->text.text.tokenise(sampleBroken, '\n');
    //vecgui::breakString(BMT->text.text, sampleBroken, 200);
    
    //std::cout << "Input:\n" << BMT->text.text.getString() << std::endl;
    //std::cout << "Broken String : " << sampleBroken.size() << std::endl;
    //int sbindex = 0;
    //for (const sttfont_formatted_text & sb : sampleBroken) {
	//	std::cout << "[" << sbindex << "] [" << sb.getString()  << "]" << std::endl;
	//	sbindex++;
	//	}

	// Attaching a callback
	//vTestContext->fetchElement("button")->setCallback(mCallback);
	
	// Checking an input - polling method


	// Callback method
	
	

	std::cout << "Foo " << 4.5 << std::endl;

	//FC_SetLineSpacing(gFont, -faceSize/2);
	uint64_t LAST = 0;
	uint64_t NOW = SDL_GetPerformanceCounter();
	
		SDL_GetCurrentRenderOutputSize(vTestContext->mRenderer, &windowWidth, &windowHeight);
				
			vTestContext->resizeCanvas(windowWidth/vTestContext->scalef, windowHeight/vTestContext->scalef);
			bool isDirty = true;
	
	//Make a target texture to render too
	SDL_Texture *targetTexture = NULL;
	
	SDL_Vgui_IME_Handler mSDL_IME_Handler(mWindow);
	vTestContext->mIME_Handler = &mSDL_IME_Handler;
	
	int i = 0;
	bool programOn = true;
	while (programOn) {
		i++;
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			std::string textOut;
			switch (ev.type) {
				case SDL_EVENT_MOUSE_BUTTON_UP:
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					vTestContext->processMouseEvent(ev.button.x, ev.button.y, ev.button.button, ev.type == SDL_EVENT_MOUSE_BUTTON_DOWN);
					break;
				case SDL_EVENT_TEXT_INPUT:
					vTestContext->processTextInputEvent(ev.text.text, Vgui_TextEditEvent::VGUI_TEXTEDIT_INSERT, textOut);
				case SDL_EVENT_KEY_DOWN:
					{
						if (ev.key.key == SDLK_BACKSPACE)
							vTestContext->processTextInputEvent("", Vgui_TextEditEvent::VGUI_TEXTEDIT_BACKSPACE, textOut);
						if (ev.key.key == SDLK_RETURN)
							vTestContext->processTextInputEvent("\n", Vgui_TextEditEvent::VGUI_TEXTEDIT_INSERT, textOut);
						if (ev.key.key == SDLK_DELETE)
							vTestContext->processTextInputEvent("", Vgui_TextEditEvent::VGUI_TEXTEDIT_DELETE, textOut);
						if (ev.key.key == SDLK_LEFT)
							vTestContext->processTextInputEvent("", Vgui_TextEditEvent::VGUI_TEXTEDIT_CURSOR_LEFT, textOut);
						if (ev.key.key == SDLK_RIGHT)
							vTestContext->processTextInputEvent("", Vgui_TextEditEvent::VGUI_TEXTEDIT_CURSOR_RIGHT, textOut);
						if (ev.key.key == SDLK_UP)
							vTestContext->processTextInputEvent("", Vgui_TextEditEvent::VGUI_TEXTEDIT_CURSOR_UP, textOut);
						if (ev.key.key == SDLK_DOWN)
							vTestContext->processTextInputEvent("", Vgui_TextEditEvent::VGUI_TEXTEDIT_CURSOR_DOWN, textOut);
						if (ev.key.key == SDLK_V && (ev.key.mod & SDL_KMOD_CTRL))
							vTestContext->processTextInputEvent(SDL_GetClipboardText(), Vgui_TextEditEvent::VGUI_TEXTEDIT_INSERT, textOut);
						if (ev.key.key == SDLK_C && (ev.key.mod & SDL_KMOD_CTRL)) {
							vTestContext->processTextInputEvent("", Vgui_TextEditEvent::VGUI_TEXTEDIT_COPY, textOut);
							SDL_SetClipboardText(textOut.c_str());
							}
						if (ev.key.key == SDLK_X && (ev.key.mod & SDL_KMOD_CTRL)) {
							vTestContext->processTextInputEvent("", Vgui_TextEditEvent::VGUI_TEXTEDIT_CUT, textOut);
							SDL_SetClipboardText(textOut.c_str());
							}
					}
					break;

				case SDL_EVENT_QUIT:
					programOn = false;
					//return 1;
					break;
				}
			}
		float mx, my;
		int state;
		state = SDL_GetMouseState(&mx, &my);
		vTestContext->pollMouseState(mx, my, state);
		
		//std::cout << "mousePosmousePosmousePosmousePosmousePosmousePos: " << mx << ", " << my << std::endl;
		
		if (vTestContext->fetchBool("button")) {
			vTestContext->fetchElement("button")->value = 0.0;
			std::cout << "Pressed!" << std::endl;
			}

	
		//if (i % 10 == 7) {
		//	static int fooc = 1;
		//	Vgui_MultilineText * BMT = (Vgui_MultilineText*) vTestContext->fetchElement("mltext");
		//	sttfont_formatted_text foot;
		//	foot << vecgui::itos(fooc++) << " This is a row added on!";
		//	BMT->addLine (foot);
		//	}

		if (true) {
			const int windowWidth_old = windowWidth;
			const int windowHeight_old = windowHeight;
			
			SDL_GetCurrentRenderOutputSize(vTestContext->mRenderer, &windowWidth, &windowHeight);
			
			if (windowWidth_old != windowWidth || windowHeight_old != windowHeight || !targetTexture) {
				vTestContext->resizeCanvas(windowWidth/vTestContext->scalef, windowHeight/vTestContext->scalef);
				
				isDirty = true;
				//i = 0;
				
				if (VGUI_DO_DELTA_DRAWING) {
					if (targetTexture) SDL_DestroyTexture(targetTexture);
					targetTexture = SDL_CreateTexture(vTestContext->mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, windowWidth, windowHeight);
					std::cout << "===============================================================================================================" << std::endl;
					}
				}
			}
		
		
		if (targetTexture)
			SDL_SetRenderTarget(vTestContext->mRenderer, targetTexture);
			
		if (isDirty) {
			vTestContext->clear();
			}
			
		
		vTestContext->draw(isDirty);
		
		
		// test raw shapes
		#if 0
		vTestContext->setColorF(1,0,0,1);
		vTestContext->renderTriangle(200, 0, 250, 50, 250, 0);
		
		vTestContext->setGradient(0,0,100,00, 255, 0, 255, 255, 0, 255, 0, 255);
		vTestContext->renderTriangle(0, 0, 100, 0, 100, 100);
		
		vTestContext->renderRoundedQuadWH(10, 100, 180, 180, 40);
		vTestContext->clearGradient();
		#endif
		
		isDirty = !VGUI_DO_DELTA_DRAWING;
			
		if (VGUI_DO_DELTA_DRAWING) {
			SDL_SetRenderTarget(vTestContext->mRenderer, NULL);
			SDL_RenderClear(vTestContext->mRenderer);
			SDL_RenderTexture(vTestContext->mRenderer, targetTexture, NULL, NULL);
			SDL_RenderPresent(vTestContext->mRenderer);
			}
		else {
			SDL_RenderPresent(mSdlRenderer);
			}
		SDL_UpdateWindowSurface(mWindow);

		if (true) {
			SDL_Delay(15);
			}
		else if (i % 100 == 0) {
			LAST = NOW;
			NOW = SDL_GetPerformanceCounter();
			const double deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() ) / 100.0;
			std::cout << "100 Frames Average - Frametime: " << deltaTime << "ms \t FPS: " << (1000.0/deltaTime) << std::endl;
			}
		}

	//return cleanup(vTestContext);
	
	vTestContext->gFont = NULL;
	delete gFont;
	
	//std::cout << Vgui_StyleStuff::primative::allocCount << std::endl;
	cleanup(vTestContext);
	
	SDL_DestroyRenderer(mSdlRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
	}
#undef LZZ_INLINE
#endif //VECGUI_IMPL_DOUBLE_GUARD_example
#endif //VECGUI_IMPL_IMPL
