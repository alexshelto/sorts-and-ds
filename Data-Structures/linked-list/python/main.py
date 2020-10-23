# Alexander Shelton
# Linked list implementation in python
# Class Song == Node class
# Class Playlist == linkedlist class



#class song is the node class
#contains a song and artist field
#contains a pointer "next" points to next node in list or None
class Song:
  def __init__(self, song, artist):
    self.song = song
    self.artist = artist
    self.next = None


#class playlist is the linked list class
class Playlist:
  def __init__(self):
    self.head = None
  
  def show(self):
    print('*' * 40) #format to easilly see songs
    tmp = self.head
    songNum = 1
    while(tmp):
      print('{}.) {} | {}').format(songNum, tmp.artist, tmp.song)
      tmp = tmp.next
      songNum += 1
    
    print('*' * 40 + '\n') #end format


  #push mimics "play next" adds song to front of list
  def push(self, song, artist):
    new_head = Song(song, artist)
    new_head.next = self.head
    self.head = new_head


  #append mimics "play last" adds song to the end of a playlist
  def append(self, song, artist):
    tmp = self.head
    while(tmp.next):
      tmp = tmp.next

    tmp.next = Song(song, artist)
    tmp.next.next = None


  #remove song deletes a song from the list
  def removeSong(self, target_song):
    #check if target song is the head:
    if(self.head.song == target_song):
      self.pop()
      return
    
    #else traverse list till reached the target song or end of list
    tmp = self.head
    while(tmp and tmp.song != target_song):
      dptr = tmp
      tmp = tmp.next
    
    if(tmp == None):return
    else:
      dptr.next = tmp.next
      
    

  #removes the first song from the playlist
  def pop(self):
    if self.head is not None:
      self.head = self.head.next 
      




#driver function
if __name__ == '__main__':
  playlist = Playlist()

  #adding some songs to front and end of playlist
  playlist.push("Man Now", "G Herbo")
  playlist.append("Stairway to Heaven", "Led Zeppelin")
  playlist.push("Whacha Say", "Jason Derulo")
  playlist.append("Anthem, Pt. 2", "Blink-182")
  playlist.push("Fat Lip", "Sum 41")

  playlist.show() #displaying playlist
  playlist.removeSong("Stairway to Heaven") #removing a song
  # print("\n") #clearing console
  playlist.show()#displaying playlist again

  exit(0)
