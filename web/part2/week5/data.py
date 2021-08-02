albums = {}

def get_data():
    # Get from file to list of the splitted data
    albs = []
    with open("Pink_Floyd_DB.txt", "r") as f:
        all_text = f.read()[1:].lower()

        albs = all_text.split("#")
        for i in range(len(albs)):
            albs[i] = albs[i].split("*")
            for j in range(len(albs[i])):
                albs[i][j] = albs[i][j].split("::")
    
    for i in albs:
        albums[i[0][0]] = {}
        for j in i[1:]:
            # Add ["song_name":("authour", "time", "lyrics")] to albums[album] dictionary
            albums[i[0][0]][j[0]] = (j[1], j[2], j[3])


def get_list_of_albums():
    return albums.keys()


def get_songs_in_album(alb):
    try:
        return albums[alb].keys()
    except KeyError:
        return


def get_length_of_song(song):
    for i in albums.values():
        if song in i.keys():
            return i[song][1]


def get_lyrics_of_song(song):
    for i in albums.values():
        if song in i.keys():
            return i[song][2]


def get_album_of_song(song):
    for i, v in enumerate(albums.values()):
        if song in v.keys():
            return list(albums.keys())[i]


def search_in_song_titles(phrase):
    l = []
    for i in albums.values():
        for song in i.keys():
            if phrase.lower() in song.lower():
                l.append(song)
    return l


def search_in_song_lyrics(phrase):
    l = []
    for i in albums.values():
        for details, song in zip(i.values(), i.keys()):
            if phrase.lower() in details[2].lower():
                l.append(song)
    return l

get_data() # Gets the data to the albums variable, needed even if used as library