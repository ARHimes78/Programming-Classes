// Lottery.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Create a lottery game
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesP1
{
    class Lottery
    {
        public static void Main(string[] args)
        {
            Header();

            Random random = new Random();
            int lotto1, lotto2, lotto3, guess1, guess2, guess3;
            string another = "";
            double total = 0.0;//will continue to increase until program ends

            do
            {
                /*lottoNumbers will contain 3 lotto numbers, 
                guessNumbers will contain the 3 guessed numbers.
                The two strings will be compared for matches.
                They will be used many times throughout the program.
                */
                string lottoNumbers = "";
                string guessNumbers = "";

                lotto1 = random.Next(1, 5);
                lotto2 = random.Next(1, 5);
                lotto3 = random.Next(1, 5);

                lottoNumbers += lotto1.ToString();
                lottoNumbers += lotto2.ToString();
                lottoNumbers += lotto3.ToString();

                Console.WriteLine("Guess 3 numbers between 1 and 4.");

                //Will return a string of 3 numbers between 1 and 4.
                guessNumbers = CreateGuessString();

                /*
                //Uncomment this to check for 3 matching in order ($10,000 awarded)
                guessNumbers = lottoNumbers;
                */

                //The 3 string elements (chars) of the guessNumbers are converted to ints.
                guess1 = (int)guessNumbers[0] - 48;
                guess2 = (int)guessNumbers[1] - 48;
                guess3 = (int)guessNumbers[2] - 48;

                Console.WriteLine("\nThe lottery numbers are {0}, {1} and {2}.",
                    lotto1, lotto2, lotto3);
                Console.WriteLine("The guessed numbers are {0}, {1} and {2}.",
                    guess1, guess2, guess3);

                int points = 0;//Will be used to determine how much money is awarded.
                bool aMatchOccured = false;

                //At this point, the number of matching numbers between the number strings are counted.
                points = CountMatchingNumbers(lottoNumbers, guessNumbers);

                if (points != 0)
                {
                    aMatchOccured = true; //if there is at least one match.
                }

                //Because of inaccuracies, the points are updated to the correct number of matches.
                points = MatchCorrection(points, aMatchOccured, lottoNumbers, guessNumbers);

                /*The points will determine the total.
                To check for three matching numbers with the same order,
                the two strings are tested for identical values.
                */
                total += Winnings(points, lottoNumbers, guessNumbers);

                Console.WriteLine("\nTotal won amount: {0:C}.", total);

                //Prompt user for another Lottery game
                Console.Write("\nDo you want to do again? (y/n): ");
                another = Console.ReadLine();
            } while (another[0].ToString().ToLower() == "y");
        }

        private static void Header()
        {
            //program header
            Console.WriteLine("Alan Himes");
            Console.WriteLine("Program 1: Lottery");
            Console.WriteLine("Create a lottery game");
        }

        private static string CreateGuessString()
        {
            bool valid;
            string guess = "";
            string gn = "";//will be returned to guessNumbers

            //Iterate through 3 number guessing prompts and validate input each time.
            for (int i = 0; i < 3; i++)
            {
                do
                {
                    Console.Write("Guess #{0}: ", i + 1);
                    guess = Console.ReadLine();

                    if (NumberCheck(guess))//Check validity of input
                    {
                        gn += guess;
                        valid = true;
                    }
                    else
                        valid = false;

                } while (valid == false);
            }

            return gn;
        }

        //To be used in CreateGuessString().
        private static bool NumberCheck(string numCheck)
        {
            int num;

            //Test to see whether input is a number and within range.
            if (int.TryParse(numCheck, out num))
            {
                if (num >= 1 && num <= 4)
                {
                    return true;
                }
                else
                {
                    Console.WriteLine("Number must be between 1 and 4!");
                    return false;
                }
            }
            else
            {
                Console.WriteLine("Not a number!");
                return false;
            }
        }

        private static int CountMatchingNumbers(string ln, string gn)
        {
            int count = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (ln[i] == gn[j])
                    {
                        count++;

                    }
                }
            }

            return count;
        }

        private static int MatchCorrection(int pts, bool match, string ln, string gn)
        {
            /*If any of the sets of numbers have a repeated number, an extra "point" is added.
            Example: 111 vs 131 would be 6 matching points, not 2.
            RepeatedNumbers(string) will return a number of matches to be subtracted 
            from the point count.
            */
            pts -= RepeatedNumbers(ln);
            pts -= RepeatedNumbers(gn);

            /*If one of the sets of numbers has a repeated number that doesn't match
            the other set, the points amount could be a negative number.
            */
            if (pts < 0)
            {
                pts = 0;
            }

            /*The only problem left is if one set has 3 numbers and another has 1.
            For example, with 111 and 132, the points are 0.
            Three matching numbers in the same set subtracts 3 points.
            */
            if (match && pts == 0)
            {
                pts = 1;
            }

            return pts;
        }

        //to be used in MatchCorrection(int, bool, string, string)
        private static int RepeatedNumbers(string numberSet)
        {
            int repeatCount = 0;
            if (numberSet[0] == numberSet[1])
            {
                repeatCount++;
            }

            if (numberSet[0] == numberSet[2])
            {
                repeatCount++;
            }

            if (numberSet[1] == numberSet[2])
            {
                repeatCount++;
            }

            return repeatCount;
        }

        private static double Winnings(int pts, string ln, string gn)
        {
            double earnings = 0.0;

            switch (pts)
            {

                case 0:
                    Console.WriteLine("{0} matching numbers. You win {1:C}.",
                        pts, Math.Pow(10, pts) - 1);//just to be fancy
                    break;
                case 1:
                    Console.WriteLine("{0} matching number. You win {1:C}!",
                        pts, Math.Pow(10, pts));
                    earnings = 10.0;
                    break;
                case 2:
                    Console.WriteLine("{0} matching numbers. You win {1:C}!",
                        pts, Math.Pow(10, pts));
                    earnings = 100.0;
                    break;

                case 3:
                    if (ln == gn)//Check for 3 matching in exact order
                    {
                        Console.Write("Jackpot! You win $10,000.00!!");
                        Console.WriteLine(" Wait... this isn't a slot machine.");
                        earnings = 10000.0;

                    }
                    else//3 matching, not in exact order
                    {
                        Console.WriteLine("{0} matching numbers. You win {1:C}!",
                            pts, Math.Pow(10, pts));
                        earnings = 1000.0;
                    }
                    break;
                default:
                    Console.WriteLine("{0} matching numbers. The programmer messed up!", pts);
                    break;
            }

            return earnings;
        }
    }
}

