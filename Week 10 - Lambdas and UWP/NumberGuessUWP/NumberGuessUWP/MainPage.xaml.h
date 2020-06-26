//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include <string>
#include <iostream>
#include <random>
using namespace std;

namespace NumberGuessUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	private:
		int numToGuess = 50;
		//int guess;
		random_device rnd;
	public:
		MainPage();

		void PickRandomNumber();
	private:
		void guessButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void newGameButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
