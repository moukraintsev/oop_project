#ifndef FILM_H
#define FILM_H

#include "video.h"

class Film: public Video {

public:
    // Сonstructors
    Film();
    Film(const std::string &, const int &, const std::string &, const std::string &, const bool &, const std::string &);
    Film(const Film &);

    // Getters
    const std::string &getStyle()const;

    // Setters
    void setStyle(const std::string &);

    VideoType getType() const override;

    bool operator == (Film *);

private:
    std::string style;
};

#endif // FILM_H
