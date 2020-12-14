#ifndef VIDEOCOLLECTION_H
#define VIDEOCOLLECTION_H

#include <fstream>
#include <sstream>
#include <vector>
#include <video.h>
#include <series.h>
#include <film.h>


class VideoCollection
{
public:
    VideoCollection();
    VideoCollection(int);
    VideoCollection(const VideoCollection&);
    ~VideoCollection();

    Video* getVideo(const int &)const;
    std::vector<Video*> getVideos();
    int getNumber() const;

    bool contain(Video*) const;

    void addVideo(Video*);
    void dellVideo(const std::string &);
    Video* searchVideo(std::string&);
    void clear();

    void readFile(const std::string&);
    void writeFile(const std::string&) const;


private:
    std::vector<Video*> videoContainer;
    int number;
};

#endif // VIDEOCOLLECTION_H
