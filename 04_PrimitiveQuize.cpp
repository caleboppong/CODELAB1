#include <iostream>         //this is the stream library for input and output console.
#include <vector>           //this is for using dynamic arrays (vectors)
#include <algorithm>        // this is for standard algorithms like transform and shuffle
#include <cctype>           // this is for character manipulation (e.g., tolower)
#include <random>           // This is for random number generation

// this function is to convert a given string to lowercase (case-insensitive comparison)
std::string toLower(const std::string& str) {
    std::string result = str;

    // this transforms each character in the string to lowercase
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

// This function returns a shuffled list of country-capital pairs
std::vector<std::pair<std::string, std::string>> getShuffledQuestions() {

    // Few list of 10 European countries and their capitals
    std::vector<std::pair<std::string, std::string>> questions = {
        {"Denmark", "Copenhagen"},
        {"Germany", "Berlin"},
        {"Finland", "Helsinki"},
        {"Spain", "Madrid"},
        {"Italy", "Rome"},
        {"Greece", "Athens"},
        {"Netherlands", "Amsterdam"},
        {"Romania", "Bucharest"},
        {"Austria", "Vienna"},
        {"France", "Paris"}
    };

    // This is random number generator 

    std::random_device rd;      // Obtains a random seed from the hardware
    std::mt19937 g(rd());       // Mersenne Twister engine seeded with rd()

    // Shuffle the vector to randomize the order of questions
    std::shuffle(questions.begin(), questions.end(), g);
    return questions;
}

int main() {
    // Welcome output and quiz guide
    std::cout << "Welcome to the European Capital Cities Quiz!\n";
    std::cout << "Provide your answer and press Enter.\n\n";

    // Get the randomized list of questions
    auto questions = getShuffledQuestions();
    int score = 0;  // Keeps track of the number of correct answers

    // Loop through each question in the shuffled list
    for (size_t i = 0; i < questions.size(); ++i) {
        std::cout << "Q" << i + 1 << ": Tell me the capital of " << questions[i].first << "? ";
        std::string userAnswer;
        std::getline(std::cin, userAnswer);  // Read the user's input

        // Compare user's answer (converted to lowercase) to the correct answer (also lowercase)
        if (toLower(userAnswer) == toLower(questions[i].second)) {
            std::cout << "✅ Correct!\n\n";
            score++;  // Increment score for a correct answer
        } else {
            std::cout << "❌ Wrong. The correct answer is: " << questions[i].second << "\n\n";
        }
    }

    // It shows the final score and outputs a message based on performance
    std::cout << "🎉 Well done! Your final score: " << score << "/10\n";

    // this gives feedback based on score ranges
    if (score == 10) {
        std::cout << "🏆 Perfect score! You're a geography master!\n";
    } else if (score >= 7) {
        std::cout << "👍 Nice one!\n";
    } else {
        std::cout << "📘 Keep practicing!\n";
    }

    return 0;  // End of program
}
