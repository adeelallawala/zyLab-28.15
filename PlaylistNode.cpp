#include <iostream>
#include <string>
using namespace std;

#include "PlaylistNode.h"

PlaylistNode::PlaylistNode() {
  uniqueID = "none";
  songName = "none";
  artistName = "none";
  songLength = 0;
}

PlaylistNode::PlaylistNode(string id, string name, string artist, int length) {
  uniqueID = id;
  songName = name;
  artistName = artist;
  songLength = length;
}

string PlaylistNode::GetID() {
  return uniqueID;
}

string PlaylistNode::GetSongName() {
  return songName;
}

string PlaylistNode::GetArtistName() {
  return artistName;
}

int PlaylistNode::GetSongLength() {
  return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
  return nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
	PlaylistNode* tmpNext = this->nextNodePtr;
	this->nextNodePtr = nodeLoc;
	nodeLoc->nextNodePtr = tmpNext;
}

void PlaylistNode::SetNext(PlaylistNode* nodeLoc) {
	this->nextNodePtr = nodeLoc;
}

void PlaylistNode::PrintPlaylistNode() {
  cout << "Unique ID: " << uniqueID << endl;
  cout << "Song Name: " << songName << endl;
  cout << "Artist Name: " << artistName << endl;
  cout << "Song Length (in seconds): " << songLength << endl;
}