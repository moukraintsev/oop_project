#ifndef SERIES_H
#define SERIES_H

#include "video.h"

class Series: public Video {

public:
    // Сonstructors
    Series();
    Series(const std::string &, const int &, const std::string &,const std::string &,
           const bool &, const int &, const int &);
    Series(const Series &);

   // Getters
    const int& getNumberOfSeasons() const;
    const int& getNumberOfEpisodes() const;

   // Setters
    void setNumberOfSeasons(const int &);
    void setNumberOfEpisodes(const int &);

    bool operator == (Series*);

    VideoType getType() const override;

private:
    int numberOfSeasons;
    int numberOfEpisodes;
};

#endif // SERIES_H
