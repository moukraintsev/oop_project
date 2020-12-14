#include "video.h"


Video::Video() {
    this -> name = "NoName";
    this -> year = 1895;
    this -> country = "NoName";
    this -> duration = "00:00:00";
    this -> isViewed = false;
}

Video::Video(const Video &sourceVideo) {
    this -> name = sourceVideo.getName();
    this -> year = sourceVideo.getYear();
    this -> country = sourceVideo.getCountry();
    this -> duration = sourceVideo.getDuration();
    this -> isViewed = sourceVideo.getView();
}

Video::Video(const std::string &nameSource, const int &yearSource, const std::string &countrySource, const std::string &durationSource, const bool &isViewedSource) {
    if (nameSource.length() != 0) {
        this -> name = nameSource;
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);
    if (yearSource < 1895 &&  yearSource <= 1970 + ltm -> tm_year) {
        this -> year = yearSource;
    }

    if (countrySource.length() != 0) {
        this -> country = countrySource;
    }

    if (durationSource.length() == 8 && isdigit(durationSource[0]) && isdigit(durationSource[1]) && isdigit(durationSource[3]) && isdigit(durationSource[4])
                                     && isdigit(durationSource[6]) && isdigit(durationSource[7]) && durationSource[2] == ':' && durationSource[5] == ':') {
        this -> duration = durationSource;
    }

    this -> isViewed = isViewedSource;

}

const std::string &Video::getName() const {
    return this -> name;
}

const int &Video::getYear() const {
    return this -> year;
}

const std::string &Video::getCountry() const {
    return this -> country;
}

const std::string &Video::getDuration() const {
    return this -> duration;
}

const bool &Video::getView() const {
    return this -> isViewed;
}

void Video::setName(const std::string &newName) {
    if (newName.length())
        this -> name = newName;
}

void Video::setYear(const int &newYear) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    if (newYear > 1896 && newYear < 1970 + ltm -> tm_year)
        this -> year = newYear;
}

void Video::setCountry(const std::string &newCountry) {
    if (newCountry.length() != 0)
        this -> country = newCountry;
}

void Video::setDuration(const std::string &newDuration) {
    if (newDuration.length() == 8 && isdigit(newDuration[0]) && isdigit(newDuration[1]) && isdigit(newDuration[3]) && isdigit(newDuration[4])
                                  && isdigit(newDuration[6]) && isdigit(newDuration[7]) && newDuration[2] == ':' && newDuration[5] == ':')
        this -> duration = newDuration;
}

void Video::setView(const bool &newViewStatus) {
    this -> isViewed = newViewStatus;
}
