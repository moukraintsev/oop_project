#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <ctime>

enum VideoType {film, series};

class Video {

public:
    // Сonstructors
    Video();
    Video(const Video &);
    Video(const std::string &, const int &, const std::string &, const std::string &, const bool &);

    // Getters
    const std::string &getName() const;
    const int &getYear() const;
    const std::string &getCountry() const;
    const std::string &getDuration() const;
    const bool &getView()const;

    // Setters
    void setName(const std::string &);
    void setYear(const int &);
    void setDuration(const std::string &);
    void setCountry(const std::string &);
    void setView(const bool &);

    virtual VideoType getType() const = 0;

protected:
    std::string name;
    int year;
    std::string country;
    std::string duration;
    bool isViewed;
};

#endif // VIDEO_H
