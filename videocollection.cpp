#include "videocollection.h"
#include <iostream>
#include <string>


VideoCollection::VideoCollection() {
    this -> number = 0;
    this -> videoContainer.reserve(number);
}

VideoCollection::VideoCollection(int new_number){
    this -> number = new_number;
    this -> videoContainer.reserve(new_number);
}

VideoCollection::VideoCollection(const VideoCollection &other_data){
    this -> number = other_data.number;
    this -> videoContainer = other_data.videoContainer;
}

VideoCollection::~VideoCollection(){
    this -> videoContainer.clear();
    this -> videoContainer.shrink_to_fit();
}

Video* VideoCollection::getVideo(const int &position)const{
    return this -> videoContainer[position];
}

std::vector<Video*> VideoCollection::getVideos(){
    return this -> videoContainer;
}

int VideoCollection::getNumber() const {
    return videoContainer.size();
}

void VideoCollection::addVideo(Video *video){
    if (video -> getType() == series)
        {
            videoContainer.push_back(new Series(*dynamic_cast<Series*>(video)));
        }
        else if (video -> getType() == film)
        {
            videoContainer.push_back(new Film(*dynamic_cast<Film*>(video)));
        }
    this -> number = videoContainer.size();
}

bool VideoCollection::contain(Video *other_video) const{
    bool f;
    for (int i = 0; i < this -> videoContainer.size(); i++){
        if (videoContainer[i]->getType() == series && other_video->getType() == series){
           f = dynamic_cast<Series*>(videoContainer[i]) == dynamic_cast<Series*>(other_video);
        }
        else if (videoContainer[i]->getType() == film && other_video->getType() == film){
           f = dynamic_cast<Film*>(videoContainer[i]) == dynamic_cast<Film*>(other_video);
        }
    }
    return f;
}

void VideoCollection::clear(){
    this -> videoContainer.clear();
}

Video* VideoCollection::searchVideo(std::string &video_name) {
    int size = videoContainer.size();
    for (int i = 0; i < size; i++){
        if (videoContainer[i] -> getName() == video_name)
            return videoContainer[i];
    }
    return nullptr;
}

void VideoCollection::readFile(const std::string &filename){
    std::ifstream file(filename);
        if (file.is_open())
        {
            while (!file.eof())
            {
                std::string word;
                std::getline(file, word);

                if (word == "Series")
                {
                    Series *temp = new Series;

                    std::getline(file,word);
                    temp -> setName(word);

                    std::getline(file,word);
                    temp -> setYear(std::stoi(word));

                    std::getline(file,word);
                    temp -> setDuration(word);

                    std::getline(file,word);
                    temp -> setCountry(word);

                    std::getline(file,word);
                    temp -> setNumberOfSeasons(std::stoi(word));

                    std::getline(file,word);
                    temp -> setNumberOfEpisodes(std::stoi(word));

                    std::getline(file,word);
                    if (word == "0")
                        temp -> setView(false);
                    if (word == "1")
                        temp -> setView(true);

                    this -> addVideo(temp);

                } else if (word == "Film") {

                    Film *temp = new Film;

                    std::getline(file,word);
                    temp -> setName(word);

                    std::getline(file,word);
                    temp -> setYear(std::stoi(word));

                    std::getline(file,word);
                    temp -> setDuration(word);

                    std::getline(file,word);
                    temp -> setCountry(word);

                    std::getline(file,word);
                    temp -> setStyle(word);

                    std::getline(file,word);
                    if (word == "0")
                        temp -> setView(false);
                    if (word == "1")
                        temp -> setView(true);

                    this -> addVideo(temp);
                }
            }
            file.close();
        }
}

void VideoCollection::writeFile(const std::string& filename) const{

    std::ofstream file;
    file.open(filename);
    for (int i = 0; i < videoContainer.size(); ++i)
    {
        if (videoContainer[i] -> getType() == series) {
            file << "Series" << std::endl;
            file << videoContainer[i]->getName() << std::endl;
            file << videoContainer[i]->getYear() << std::endl;
            file << videoContainer[i]->getDuration() << std::endl;
            file << videoContainer[i]->getCountry() << std::endl;
            file << dynamic_cast<Series*>(videoContainer[i]) -> getNumberOfSeasons() << std::endl;
            file << dynamic_cast<Series*>(videoContainer[i]) -> getNumberOfEpisodes() << std::endl;
            file << dynamic_cast<Series*>(videoContainer[i]) -> getView() << std::endl;
        } else if (videoContainer[i] -> getType() == film) {
            file << "Film" << std::endl;
            file << videoContainer[i]->getName() << std::endl;
            file << videoContainer[i]->getYear() << std::endl;
            file << videoContainer[i]->getDuration() << std::endl;
            file << videoContainer[i]->getCountry() << std::endl;
            file << dynamic_cast<Film*>(videoContainer[i])->getStyle() << std::endl;
            file << dynamic_cast<Film*>(videoContainer[i])->getView() << std::endl;
        }
    }
    file.close();
}

void VideoCollection::dellVideo(const std::string &video_name) {
    int size = videoContainer.size();
    for (int i = 0; i < size; i++) {
        if (videoContainer[i] -> getName() == video_name) {
            videoContainer.erase(videoContainer.begin() + i);
        size = videoContainer.size();
        }
    }
}
