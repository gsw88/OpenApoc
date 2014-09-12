
#include "basescreen.h"
#include "../../framework/framework.h"

BaseScreen::BaseScreen()
{
    basescreenform = GAMECORE->GetForm("FORM_BASESCREEN");
}

BaseScreen::~BaseScreen()
{
}

void BaseScreen::Begin()
{
}

void BaseScreen::Pause()
{
}

void BaseScreen::Resume()
{
}

void BaseScreen::Finish()
{
}

void BaseScreen::EventOccurred(Event *e)
{
    basescreenform->EventOccured( e );
	GAMECORE->MouseCursor->EventOccured( e );

	if( e->Type == EVENT_KEY_DOWN )
	{
		if( e->Data.Keyboard.KeyCode == ALLEGRO_KEY_ESCAPE )
		{
			delete FRAMEWORK->ProgramStages->Pop();
			return;
		}
	}
}

void BaseScreen::Update()
{
    basescreenform->Update();
}

void BaseScreen::Render()
{
	al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
    basescreenform->Render();
	GAMECORE->MouseCursor->Render();
}

bool BaseScreen::IsTransition()
{
	return false;
}
