* Filename: grader.cpp
* Description: Output the Number of Grades read in from the file. Calculate and output the
Total Points Earned. Calculate and output the Total Possible Points. (Remember each grade is
out of a possible 100 points max.) Finally, output the Final Grade as a letter grade and
percentage, such that it lines up with the previous output
*/ 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

// Function prototypes
int ProcessFile(std::ifstream &file, int &numGrades, int &totalPoints);
double CalculateFinalGrade(int totalPoints, int maxPoints);
char CalculateLetter(double finalGrade);

int main() {
    std::string filename;
    std::cout << "Enter the input file: ";
    std::cin >> filename;

    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << filename << " does not exist." << std::endl;
        return 1; // Exit if file doesn't exist
    }

    int numGrades = 0, totalPoints = 0;
    int maxPoints = ProcessFile(file, numGrades, totalPoints);
    file.close(); // Close file after reading

    // Calculate final grade
    double finalGrade = CalculateFinalGrade(totalPoints, maxPoints);
    char letterGrade = CalculateLetter(finalGrade);

    // Output results
    std::cout << std::endl;
    std::cout << "Number of Grades:       " << std::setw(5) << numGrades << std::endl;
    std::cout << "Total Points Earned:    " << std::setw(5) << totalPoints << std::endl;
    std::cout << "Max Possible Points:    " << std::setw(5) << maxPoints << std::endl;
    std::cout << std::endl;
    std::cout << "Final Grade: " << std::setw(7) << letterGrade << "     " << std::fixed << std::setprecision(1) << finalGrade << "%" << std::endl;

    return 0;
}

// Function to process the file and calculate the number of grades, total points, and max points
int ProcessFile(std::ifstream &file, int &numGrades, int &totalPoints) {
    int grade;
    while (file >> grade) {
        numGrades++;
        totalPoints += grade;
    }
    return numGrades * 100; 
}

// Function to calculate the final grade percentage
double CalculateFinalGrade(int totalPoints, int maxPoints) {
    if (maxPoints == 0) {
        return 0.0; 
    }
    return (static_cast<double>(totalPoints) / maxPoints) * 100;
}

// Function to calculate the letter grade based on the final grade percentage
char CalculateLetter(double finalGrade) {
    if (finalGrade >= 90.0) {
        return 'A';
    } else if (finalGrade >= 80.0) {
        return 'B';
    } else if (finalGrade >= 70.0) {
        return 'C';
    } else if (finalGrade >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

