#include <cmath>
#include <string>
#include <iostream>
using namespace std;

// Takes a note and returns its frequency

// Based on https://gist.github.com/stuartmemo/3766449 

float GetFrequency(string note)
{
    std::vector<std::string> notes = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
    float octave = (note.back() - '0');
    note.pop_back();

    float keyNumber = std::distance(notes.begin(), std::find(notes.begin(), notes.end(), note));

    if (keyNumber < 3)
    {
        keyNumber += octave * 12 + 1;
    }
    else 
    {
        keyNumber += (octave - 1) * 12 + 1;
    }

    float freq = 440 * pow(2, (keyNumber - 49) / 12);

    return freq;
}
