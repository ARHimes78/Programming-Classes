// CowboysAliensForm.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Create Cowboys and Aliens game

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CowboysAliens;

namespace HimesP5
{
    public partial class CowboysAliensForm : Form
    {
        private bool gameMode;//True for game in progress, false for game not in progress.
        Alien[] aliens;       
        private Location[] locs;
        private Random random;
        private int totalAliens, startingLocation, youveBeenHit, maxHits;
        private bool isHiding;
        private OutsideWithHidingPlace outsideHiding1;
        private OutsideWithHidingPlace outsideHiding2;
        private Building building1;
        private Building building2;
        private Building building3;
        private Outside outside1;
        private Outside outside2;

        private ComboBox[] combos;
        
        public CowboysAliensForm()
        {            
            InitializeComponent();
            random = new Random();
            gameMode = false;//Used for making form items visible/invisible.
            InitializeForm();

            maxHits = 2;//Fair for the aliens??
            youveBeenHit = 0;//increments whenever shot.

            //7 aliens each assigned a random location.
            aliens = new Alien[totalAliens];
            for (int i = 0; i < totalAliens; i++)
            {
                aliens[i] = new Alien(random.Next(0, 7));
            }

            startingLocation = aliens[totalAliens - 1].AlienLocation;

            //Randomly constructed sentence will be descriptions for hiding places.
            string[] whereHow = new string[] { "under a ", "behind a ", "in the shadow of a ", "somewhere around a ", "while camoflaging against a " };
            string[] whatOutside = new string[] { "bush.", "tree.", "rock.", "fountain.", "car." };
            string[] whatInside = new string[] { "telephone.", "column.", "refrigerator.", "table.", "bathroom." };

            outsideHiding1 = new OutsideWithHidingPlace("Outside with hiding place 1");
            outsideHiding1.HidingPlaceName = whereHow[random.Next(0, 5)] + whatOutside[random.Next(0, 5)];
            outsideHiding1.Description = "A public meeing area.";
            outsideHiding2 = new OutsideWithHidingPlace("Outside with hiding place 2");
            outsideHiding2.HidingPlaceName = whereHow[random.Next(0, 5)] + whatOutside[random.Next(0, 5)];
            outsideHiding2.Description = "A parking lot.";
            building1 = new Building("Building 1");
            building1.HidingPlaceName = whereHow[random.Next(0, 5)] + whatInside[random.Next(0, 5)];
            building1.Description = "An office building.";
            building2 = new Building("Building 2");
            building2.HidingPlaceName = whereHow[random.Next(0, 5)] + whatInside[random.Next(0, 5)];
            building2.Description = "A grocery store.";
            building3 = new Building("Building 3");
            building3.HidingPlaceName = whereHow[random.Next(0, 5)] + whatInside[random.Next(0, 5)];
            building3.Description = "A restaurant.";
            outside1 = new Outside("Outside 1");
            outside1.Description = "A city park.";
            outside2 = new Outside("Outside 2");
            outside2.Description = "An open field.";

            locs = new Location[] { outsideHiding1, outsideHiding2, building1, building2, building3, outside1, outside2 };

            UpdateStatusScreen(totalAliens, locs[startingLocation].Name); 
        }

        private void InitializeForm()
        {         
            totalAliens = 7;//This will decrement every time an alien dies, and serve as an array key for "the current alien".
                        
            textBoxInstructions.Text = "Check for hiding aliens if necessary, and select all of the combo boxes before pressing SHOOT.";

            //Initializing the combo boxes
            string[] weapons = new string[] { "Weapons", "Six-Shooter", "Rifle,", "Spear", "Alien Gauntlet" };
            string[] rounds = new string[] { "Rounds", "1", "2", "3", "4", "5" };
            string[] range = new string[] { "Range", "5", "25", "50", "100", "500", "1000" };
            string[] visibility = new string[] { "Visibility", "clear day", "clear night", "dusk", "fog", "smoke" };
            string[] wind = new string[] { "Wind", "0", "5", "10", "15", "20", "25" };
            string[][] choices = new string[][] { weapons, rounds, range, visibility, wind };
            combos = new ComboBox[] { comboBoxWeapons, comboBoxRounds, comboBoxRange, comboBoxVisibility, comboBoxWind };

            int j = 0;
            foreach (ComboBox combo in combos)
            {

                combo.Items.Clear();
                combo.Items.AddRange(choices[j]);
                combo.SelectedIndex = 0;
                combo.Visible = gameMode;
                ++j;
            }

            buttonStart.Visible = !gameMode;

            textBoxInstructions.Visible = gameMode;
            textBoxResults.Visible = gameMode;
            buttonShoot.Visible = gameMode;
            buttonHideCheck.Visible = gameMode;
            buttonAlienLocation.Visible = gameMode;
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            gameMode = true;
            InitializeForm();
            UpdateStatusScreen(totalAliens, locs[startingLocation].Name);
            Hiding();

            for (int i = 0; i < 5; i++)
                aliens[totalAliens-1].Move();
        }

        private void buttonShoot_Click(object sender, EventArgs e)
        {
            int comboBoxCheck = 0;
            foreach (ComboBox combo in combos)
            {
                if (combo.SelectedIndex == 0) //if any of the combo boxes hasn't been selected
                {
                    MessageBox.Show("\"" + combo.Text + "\" hasn't been selected!");
                }
                else
                {
                    ++comboBoxCheck;
                }
            }

            if (comboBoxCheck == 5)
            {
                int range = comboBoxRange.SelectedIndex - 1;
                int wind = comboBoxWind.SelectedIndex - 1;
                int visibility = comboBoxVisibility.SelectedIndex - 1;
                int rounds = comboBoxRounds.SelectedIndex - 1;
                Weapon[] weapons = new Weapon[] 
                { 
                    new SixShooter(range,wind,visibility,rounds), 
                    new Rifle(range,wind,visibility,rounds), 
                    new Spear(range,wind,visibility,rounds), 
                    new AlienGauntlet(range,wind,visibility,rounds) 
                };

                int calcHit = weapons[comboBoxWeapons.SelectedIndex - 1].ComputeHits();

                if (isHiding)
                {
                    MessageBox.Show("The alien is hiding!");
                }
                else
                {
                    int firesBack = 0;
                    string altercation = "";

                    //Results of calcHit will determine whether the alien was not hit, wounded, or killed.
                    if (calcHit == 0)
                    {
                        altercation = "You missed! The alien fires back... ";

                        firesBack = AlienFiresBack(weapons[comboBoxWeapons.SelectedIndex - 1]);

                        if (firesBack == 0)
                        {
                            altercation += "and misses.";
                        }
                        else
                        {
                            altercation += "You're hit!! You take " + firesBack + " damage.";
                            youveBeenHit += firesBack;
                        }
                        MessageBox.Show(altercation);
                    }
                    else if (calcHit == 1)
                    {
                        altercation = "You wounded one! The alien fires back... ";

                        firesBack = AlienFiresBack(weapons[comboBoxWeapons.SelectedIndex - 1]);

                        if (firesBack == 0)
                        {
                            altercation += "and misses.";
                        }
                        else
                        {
                            altercation += "You're hit!! You take " + firesBack + " damage.";
                            youveBeenHit += firesBack;
                        }                        
                    }

                    else //The alien has been hit more than once
                    {
                        totalAliens--;
                        altercation = "You killed one!";
                    }

                    MessageBox.Show(altercation);

                    if (totalAliens != 0)
                    {
                        MessageBox.Show("There is nothing to shoot here. Click \"FIND THE NEXT ALIEN LOCATION\" to find an alien.");
                        buttonShoot.Enabled = false;
                        buttonHideCheck.Enabled = false;
                    }
                    else if (totalAliens == 0)
                    {
                        MessageBox.Show("The aliens have all been defeated! You win!!");
                        GameOver();
                    }
                    else if (youveBeenHit == maxHits)
                    {
                        MessageBox.Show("Game over. You have been defeated by the aliens.");
                        GameOver();
                    }
                }                
            }
        }
             
        private void buttonHideCheck_Click(object sender, EventArgs e)
        {
            int key = aliens[totalAliens-1].AlienLocation;
            string hidingPlace = "";

            if (isHiding)//The alien is hiding
            {
                //Retreiving the HidingPlaceName value by making temporary objects.
                if (locs[key] is OutsideWithHidingPlace)
                {
                    OutsideWithHidingPlace tempOWHP = (OutsideWithHidingPlace)locs[key];
                    hidingPlace = tempOWHP.HidingPlaceName;
                    textBoxResults.Text = "The alien is hiding " + hidingPlace;
                }
                else if (locs[key] is Building)
                {
                    Building tempB = (Building)locs[key];
                    hidingPlace = tempB.HidingPlaceName;
                    textBoxResults.Text = "The alien is hiding " + hidingPlace;
                }
            }
            else
                textBoxResults.Text = "The alien is not hiding!";                      
        }

        //The player and an alien are always in the same place.
        private void buttonAlienLocation_Click(object sender, EventArgs e)
        {
            buttonShoot.Enabled = true;
            buttonHideCheck.Enabled = true;
            aliens[totalAliens-1].Move();
            UpdateLocation();            
        }

        private void UpdateStatusScreen(int alienNum, string location)
        {
            textBoxIntro.Text = "It is 1873 in a small town in New Mexico and the aliens have arrived "
            + "to invade the earth and take it over for their own nefarious purposes. "
            + "There are " + alienNum +" aliens on a recon mission to gather intelligence for the initial invasion. "
            + "Your mission is to take out the seven aliens. There is no one else. "
            + "You have four weapons: a Colt 45 Peacemaker (Six-shooter), a Sharps “Big Fifty” rifle, "
            + "a large spear, and a stolen alien-manufactured gauntlet that shoots death rays. "
            + "The aliens have superior weapons and are stronger, but they can be killed with your weapons, "
            + "but they must be hit twice. The aliens are approaching your town. "
            + "If you can find them and take them out, the aliens will assume that the earth "
            + "is too hard a target and they will leave. "
            + "\r\nAlien location: " + location + ". Click the Encounter tab to begin.";
        }

        private void UpdateLocation()
        {
            textBoxResults.Clear();
            Hiding();
            MessageBox.Show(locs[aliens[totalAliens - 1].AlienLocation].Name + "\r\n" + "Aliens remaining: " + totalAliens);
            UpdateStatusScreen(totalAliens, locs[aliens[totalAliens - 1].AlienLocation].Name);
            textBoxInstructions.Text = locs[aliens[totalAliens - 1].AlienLocation].Description;
        }

        //Whether or not the alien is hiding (or can hide) is determined here.
        private void Hiding()
        {
            if (locs[aliens[totalAliens - 1].AlienLocation] is IHidingPlace) //the current alien's location is Outside with no hiding places
                isHiding = aliens[totalAliens - 1].Check();
            else
                isHiding = false;
        }

        private int AlienFiresBack(Weapon weapon)
        {
            int chance = random.Next(1, 101);
            int hit = 0;
            switch (weapon.Rounds+1)//The object's Rounds value corresponds to the ComboBox, and needed to have 1 added.
            {
                case 1://%5 chance of getting hit
                    if (chance <= 5)
                        hit = 1;
                    break;
                case 2://%10 change of getting hit
                    if (chance <= 10)
                        hit = 1;
                    break;
                case 3://%15 change of getting hit
                    if (chance <= 15)
                        hit = 1;
                    break;
                case 4://%25 change of getting hit
                    if (chance <= 25)
                        hit = 1;
                    break;
                case 5://%40 change of getting hit
                    if (chance <= 40)
                        hit = 1;
                    break;
            }
            return hit;
        }

        private void GameOver()
        {
            gameMode = false;
            InitializeForm();
            UpdateStatusScreen(totalAliens, locs[startingLocation].Name);
        }
    }
}