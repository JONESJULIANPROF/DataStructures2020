//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <string>

using namespace NumberGuessUWP;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
	MainPage::PickRandomNumber();
	
}

void NumberGuessUWP::MainPage::PickRandomNumber()
{
	uniform_int_distribution<int> range(1, 100);
	numToGuess = range(rnd);
}


void NumberGuessUWP::MainPage::guessButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ strGuess = this->guessBox->Text;
	int guess = 0;

	try
	{
		guess = std::stoi(strGuess->Data());
	}
	catch (const std::exception&)
	{
		guess = 0;
	}

	if (guess == MainPage::numToGuess) {
		this->responseBlock->Text = "Good Job, you guessed it!";
		this->guessButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;//hide guess
		this->newGameButton->Visibility = Windows::UI::Xaml::Visibility::Visible;//show new game
	}
	else if (guess < MainPage::numToGuess) {
		this->responseBlock->Text = "Your guess is too low :(";
	}
	else if (guess > MainPage::numToGuess) {
		this->responseBlock->Text = "Your guess is too high :(";
	}
	else {
		this->responseBlock->Text = "Something weird just happend...";
	}
	this->guessBox->Focus(Windows::UI::Xaml::FocusState::Keyboard);
}


void NumberGuessUWP::MainPage::newGameButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	MainPage::PickRandomNumber();
	//cheat - display rnd number 
	//this->responseBlock->Text = MainPage::numToGuess + "";
	this->guessButton->Visibility = Windows::UI::Xaml::Visibility::Visible;//hide guess
	this->newGameButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;//show new game
	this->guessBox->Text = "";//remove the previous guess
	this->guessBox->Focus(Windows::UI::Xaml::FocusState::Keyboard);

}
