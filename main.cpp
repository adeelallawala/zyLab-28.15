//Repo Link: https://github.com/adeelallawala/zyLab-28.15
//Fawwaz Ashraf
//Abderrahim Latreche
//Adeel Allawala

#include <iostream>
#include <string>
using namespace std;

#include "PlaylistNode.h"

void PrintMenu(const string playlistTitle) {
    /* Type your code here */
    cout << playlistTitle << " PLAYLIST MENU" << endl
         << "a - Add song" << endl
         << "d - Remove song" << endl
         << "c - Change position of song" << endl
         << "s - Output songs by specific artist" << endl
         << "t - Output total time of playlist (in seconds)" << endl
         << "o - Output full playlist" << endl
         << "q - Quit" << endl;
}

void AddSongToPlaylist(PlaylistNode* headNode, string newSongID, string newSongName, string newSongArtistName, int newSongLength){
    PlaylistNode* newNode = new PlaylistNode(newSongID, newSongName, newSongArtistName, newSongLength);

    PlaylistNode* currNode = headNode;
    while (currNode->GetNext()){
        currNode = currNode->GetNext();
    }
    currNode->SetNext(newNode);
}


void ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
    switch(option){
        case 'a':
        {
            string userSongID;
            string userSongName;
            string userArtistName;
            int userSongLength;

            cin.clear();
            cin.ignore(999, '\n');

            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, userSongID);
            cout << "Enter song's name:" << endl;
            getline(cin, userSongName);
            cout << "Enter artist's name:" << endl;
            getline(cin, userArtistName);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> userSongLength;
            AddSongToPlaylist(headNode, userSongID, userSongName, userArtistName, userSongLength);

            cout << endl;
            break;
        }

        case 'd':
        {
            string userSongID;

            cin.clear();
            cin.ignore(999, '\n');

            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, userSongID);

            PlaylistNode* currSong = headNode->GetNext();
            PlaylistNode* prevSong;
            while (currSong->GetID() != userSongID){
                prevSong = currSong;
                currSong = currSong->GetNext();
            }
            //cout << "prevSong" << (prevSong->GetID()) << endl;
            //cout << "currSong" << (currSong->GetID()) << endl;
            prevSong->SetNext(currSong->GetNext());


            cout << "\"" << currSong->GetSongName() << "\" removed.";
            cout << endl << endl;

            break;
        }

        case 'c':
        {
           //we dont have to do step 9
           cout << "SKIP: DO NOT NEED TO IMPLEMENT!!!" << endl;
            break;
        }


            //starts here

        case 's':
        {
            string artistName;
            
            cin.clear();
            cin.ignore(999, '\n');

            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl << endl;
            getline(cin, artistName);

            PlaylistNode* currNode = headNode->GetNext();
            int count = 1;

            while (currNode) {
                if (currNode->GetArtistName() == artistName) {
                    cout << count << "." << endl;
                    currNode->PrintPlaylistNode();
                    cout << endl;
                }
                count++;
                currNode = currNode->GetNext();
            }

            if (count == 1) {
                cout << "No songs found for artist: " << artistName << endl;
            }

            break;
        }

         case 't':
        {
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

            PlaylistNode* currNode = headNode->GetNext();
            int totalTime = 0;

            while (currNode) {
                totalTime += currNode->GetSongLength();
                currNode = currNode->GetNext();
            }

            cout << "Total time: " << totalTime << " seconds" << endl << endl;
            break;
        }



        //ends here

        case 'o':
        {
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

            if (headNode->GetNext() == nullptr) {
                cout << "Playlist is empty" << endl << endl;
                break;
            }

            PlaylistNode* currNode = headNode;
            int i = 0;
            while (currNode->GetNext()){
                i++;
                currNode = currNode->GetNext();

                cout << i << "." << endl;
                currNode->PrintPlaylistNode();
                cout << endl;
            }
            break;
        }
        default:
            cout << "ERROR: input not validated" << endl;
            break;
    }
}

int main() {
    PlaylistNode* headNode = new PlaylistNode();

    //get playlist title from user
    string userPlaylistTitle;
    cout << "Enter playlist's title:" << endl ;
    getline(cin, userPlaylistTitle);
    cout << endl;

    //menu interface
    char userMenuOption = 'z';
    while (userMenuOption != 'q'){
        //check if valid menu option and execute if so
        if (userMenuOption == 'a' || userMenuOption == 'd' || userMenuOption == 'c' || userMenuOption == 't'|| userMenuOption == 's'  || userMenuOption == 'o'){
            ExecuteMenu(userMenuOption, userPlaylistTitle, headNode);
        }

        //prompt next choice
        PrintMenu(userPlaylistTitle);
        cout << endl << "Choose an option:" << endl;
        cin >> userMenuOption;
    }
   
   return 0;
}
