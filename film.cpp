#include "film.h"

Film::Film(): Video() {
    this -> style = "Default";
}

Film::Film(const std::string &nameSource, const int &yearSource, const std::string &countrySource, const std::string &durationSource,
           const bool &isViewedSource, const std::string &styleSource):

    Video(nameSource, yearSource, countrySource, durationSource, isViewedSource)
{
    this -> style = styleSource;
}

Film::Film(const Film &sourceFilm) {
    this -> name = sourceFilm.getName();
    this -> year = sourceFilm.getYear();
    this -> country = sourceFilm.getCountry();
    this -> duration = sourceFilm.getDuration();
    this -> isViewed = sourceFilm.getView();
    this -> style = sourceFilm.getStyle();
}

const std::string &Film::getStyle() const {
    return this -> style;
}

void Film::setStyle(const std::string &newStyle) {
    if (newStyle.length() != 0)
        this -> style = newStyle;
}

bool Film::operator == (Film *film) {
    if (this -> getName() == film -> getName() && this -> getYear() == film -> getYear() &&
        this -> getCountry() == film -> getCountry() && this -> getDuration() == film -> getDuration() &&
        this -> getStyle() == film -> getStyle()) {
        return true;
    } else {
        return false;
    }
}

VideoType Film::getType() const {
    return film;
}
