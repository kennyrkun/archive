#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <SFUI\Button.hpp>

#include <iostream>
#include <string>

bool isMouseOver(sf::Shape &object, sf::RenderWindow &window)
{
	if (object.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		return true;
	else
		return false;
}

void centertext(sf::Text &text, sf::Window &window)
{
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(window.getSize().x / 2, 40);
}

int realmain()
{
	sf::RenderWindow window(sf::VideoMode(200, 300), "Audio Recorder", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		abort();

	sf::CircleShape button;
	button.setFillColor(sf::Color::Red);
	button.setRadius(50);
	button.setOrigin(button.getLocalBounds().width / 2, button.getLocalBounds().height / 2);
	button.setPosition(100, 140);

	sf::Text buttonstatus;

	sf::Text status;
	status.setCharacterSize(20);
	status.setFillColor(sf::Color::White);
	status.setFont(font);
	status.setString("Ready.");
	centertext(status, window);

	bool button1disabled(true);
//	SFUI::Button button1(sf::Vector2f(80, 25), "Save Recording");
	SFUI::Button button1;
	button1.setPosition(sf::Vector2f(window.getSize().x / 2.0f, 230.0f));
	button1.setButtonColor(sf::Color(100, 100, 100));
	button1.setStringColor(sf::Color::White);
	button1.disable();

//	SFUI::Button button2(sf::Vector2f(80, 25), "Play Recording");
	SFUI::Button button2;
	button2.setPosition(sf::Vector2f(window.getSize().x / 2.0f, 260.0f));
	button2.setButtonColor(sf::Color(100, 100, 100));
	button2.setStringColor(sf::Color::White);
	button2.disable();

	// Here we'll use an integrated custom recorder, which saves the captured data into a SoundBuffer
	sf::SoundBufferRecorder recorder;
	const sf::SoundBuffer& buffer = recorder.getBuffer(); // get the recorded data and put it into a buffer.
	static sf::Sound sound;

	bool recording(false);
	bool playing(false);

	std::string start_recording("Start Recording.");
	std::string start_playback("Play Recording.");
	std::string stop_recording("Stop Recording.");
	std::string stop_playback("Stop Playback.");
	std::string save_recording("Save Recording.");
	std::string status_playack_finished("Playback finished.");
	std::string status_stopped("Stopped.");
	std::string status_recording("Recording...");
	std::string status_idle("Not Recording.");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					// main button
					if (isMouseOver(button, window))
					{
						if (recording == false) // start recording
						{
							std::cout << "started recording (via main button)" << std::endl;

							recorder.start(44100);
							recording = true;

							status.setString(status_recording);
							centertext(status, window);
							button.setFillColor(sf::Color::Green);

							button1.setString(stop_recording);
							button1.enable();

							button2.disable();
						}
						else // stop recording
						{
							std::cout << "stopped recording (via main button)" << std::endl;
							
							recorder.stop();
							recording = false;

							status.setString(status_stopped);
							centertext(status, window);
							button.setFillColor(sf::Color::Red);

							// Display captured sound informations
							std::cout << "Sound information:" << std::endl;
							std::cout << " " << buffer.getDuration().asSeconds() << " seconds" << std::endl;
							std::cout << " " << buffer.getSampleRate() << " samples / seconds" << std::endl;
							std::cout << " " << buffer.getChannelCount() << " channels" << std::endl;

							button1.setString(save_recording);
							button1.enable();

							button2.enable();
							button2.setString(start_playback);
						}
					}
					else if (isMouseOver(button1.m_shape, window) && !button1.disabled) // stop or save button
					{
						std::cout << "button1 depressed" << std::endl;
						button1.setButtonColor(sf::Color(60, 60, 60));
						button1.depressed = true;

						if (!recording) // save
						{
							std::cout << "saved recording to 'recording.wav'" << std::endl;

							buffer.saveToFile(".\\recording.wav");
						}
						else // stop
						{
							std::cout << "stopped recording (via stop button)" << std::endl;

							recorder.stop();
							recording = false;

							status.setString(status_stopped);
							centertext(status, window);
							button.setFillColor(sf::Color::Red);

							// Display captured sound informations
							std::cout << "Sound information:" << std::endl;
							std::cout << " " << buffer.getDuration().asSeconds() << " seconds" << std::endl;
							std::cout << " " << buffer.getSampleRate() << " samples / seconds" << std::endl;
							std::cout << " " << buffer.getChannelCount() << " channels" << std::endl;

							button1.setString(save_recording);

							button2.enable();
							button2.setString(start_playback);
						}
					}
					else if (isMouseOver(button2.m_shape, window) && !recording && !button2.disabled) // play or stop playing button
					{
						std::cout << "button2 depressed" << std::endl;
						button2.setButtonColor(sf::Color(60, 60, 60));
						button2.depressed = true;

						if (!playing) // play
						{
							std::cout << "playing recording." << std::endl;

							sound.setBuffer(buffer);
							sound.play();
							playing = true;

							button.setFillColor(sf::Color::Green);
							button2.setString(stop_playback);
						}
						else // stop playing
						{
							std::cout << "stopping recording" << std::endl;
							
							sound.stop();
							playing = false;

							status.setString(status_stopped);
							button2.setString(start_playback);
						}
					}
				} // left click
			} // mousebuttonpressed
			else if (event.type == sf::Event::MouseMoved)
			{
				if (!button1.depressed)
				{
					if (isMouseOver(button1.m_shape, window) && !button1.disabled)
						button1.setButtonColor(sf::Color(80, 80, 80));
					else
						button1.setButtonColor(sf::Color(100, 100, 100));
				}
				else
				{
					std::cout << "button1 depressed" << std::endl;
				}

				if (!button2.depressed)
				{
					if (isMouseOver(button2.m_shape, window) && !button2.disabled && !button1.depressed)
						button2.setButtonColor(sf::Color(80, 80, 80));
					else
						button2.setButtonColor(sf::Color(100, 100, 100));
				}
				else
				{
					std::cout << "button 2 depressed" << std::endl;
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				if (isMouseOver(button1.m_shape, window) && !button1.disabled)
					button1.setButtonColor(sf::Color(80, 80, 80));
				else
					button1.setButtonColor(sf::Color(100, 100, 100));

				button1.depressed = false;

				if (isMouseOver(button2.m_shape, window) && !button2.disabled)
					button2.setButtonColor(sf::Color(80, 80, 80));
				else
					button2.setButtonColor(sf::Color(100, 100, 100));

				button2.depressed = false;
			}
		} // event loop

		if (playing)
		{
			status.setString(std::to_string(sound.getPlayingOffset().asSeconds()));
			centertext(status, window);

			if (sound.getStatus() == sf::Sound::Stopped && playing) // sound is stopped playing and bool is false so we don't spam the console.
			{
				playing = false;

				std::cout << "finished playback" << std::endl;

				status.setString(status_playack_finished);
				centertext(status, window);
				button2.setString(start_playback);
				button.setFillColor(sf::Color::Red);
			}
		}

		window.clear(sf::Color(30, 30, 30));

		window.draw(button);
		window.draw(status);

		window.draw(button1);
		if (!recording)
			window.draw(button2);
//		button1.draw(window);
//		button2.draw(window);

		window.display();
	}

	return EXIT_SUCCESS;
}

int main()
{
	if (sf::SoundRecorder::isAvailable() == false)
	{
		sf::Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
			abort();

		sf::Text failtext;
		failtext.setFont(font);
		failtext.setCharacterSize(16);
		failtext.setFillColor(sf::Color::Red);
		failtext.setString("System does not support audio recording, or there is no recording device plugged in.");
		failtext.setOrigin(failtext.getLocalBounds().width / 2, failtext.getLocalBounds().height / 2);

//		SFUI::Button exit(sf::Vector2f(65, 25), "Exit");
		SFUI::Button exit;
		exit.setButtonColor(sf::Color(104, 104, 104));
		exit.setStringColor(sf::Color::White);
		exit.setString("Exit");

//		SFUI::Button retry(sf::Vector2f(65, 25), "Retry");
		SFUI::Button retry;
		retry.setButtonColor(sf::Color(104, 104, 104));
		retry.setStringColor(sf::Color::White);
		retry.setString("Retry");

		sf::RenderWindow window(sf::VideoMode(failtext.getLocalBounds().width + 25, 75), "Audio Recorder", sf::Style::Close);

		failtext.setPosition(window.getSize().x / 2.0f, 12);
		exit.setPosition(sf::Vector2f(window.getSize().x - exit.m_shape.getSize().x - 5, 50));
		retry.setPosition(sf::Vector2f(window.getSize().x - exit.m_shape.getSize().x - 70, 50));

		while(window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.key.code == sf::Mouse::Left)
					{
						if (isMouseOver(exit.m_shape, window)) // exit button
						{
							window.close();

							return EXIT_SUCCESS;
						} // exit button
						else if (isMouseOver(retry.m_shape, window)) // retry button
						{
							window.close();

							main();
						}
					} // left click
				} // mouseButtonPressed
			} // pollevent

			window.clear(sf::Color(30, 30, 30));

			window.draw(failtext);
			window.draw(retry);
			window.draw(exit);

			window.display();
		}

		return EXIT_SUCCESS;
	}
	else
	{
		realmain();
	}

	return EXIT_SUCCESS;
}
