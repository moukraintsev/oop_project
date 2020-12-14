#include "series.h"

Series::Series()
{
    this -> numberOfSeasons = 0;
    this -> numberOfEpisodes = 0;
}

Series::Series(const std::string &nameSource, const int &yearSource,
               const std::string &countrySource ,const std::string &durationSource,
               const bool &isViewedSource,
               const int &NumberOfSeasonsSource, const int &NumberOfEpisodesSource):
       Video(nameSource, yearSource, countrySource, durationSource,isViewedSource ) {

    if (NumberOfSeasonsSource > 0)
        this -> numberOfSeasons = NumberOfSeasonsSource;

    if (NumberOfEpisodesSource > 0)
        this -> numberOfEpisodes = NumberOfEpisodesSource;
}

Series::Series(const Series &sourceSeries) {
    this -> name = sourceSeries.getName();
    this -> year = sourceSeries.getYear();
    this -> duration = sourceSeries.getDuration();
    this -> country = sourceSeries.getCountry();
    this -> isViewed = sourceSeries.getView();
    this -> numberOfSeasons = sourceSeries.getNumberOfSeasons();
    this -> numberOfEpisodes = sourceSeries.getNumberOfEpisodes();
}


const int &Series::getNumberOfSeasons() const {
    return this -> numberOfSeasons;
}

const int &Series::getNumberOfEpisodes() const {
    return this -> numberOfEpisodes;
}

void Series::setNumberOfSeasons(const int &newNmberOfSeasons) {
    if (newNmberOfSeasons > 0)
          this -> numberOfSeasons = newNmberOfSeasons;
}

void Series::setNumberOfEpisodes(const int &newNumberOfEpisodes) {
    if (newNumberOfEpisodes > 0)
          this -> numberOfEpisodes = newNumberOfEpisodes;
}

bool Series::operator == (Series *series) {
    if (this -> getName() == series -> getName() && this -> getYear() == series -> getYear() &&
        this -> getCountry() == series -> getCountry() && this -> getDuration() == series -> getDuration() &&
        this -> getNumberOfSeasons() == series -> getNumberOfSeasons() &&
        this -> getNumberOfEpisodes() == series -> getNumberOfEpisodes()) {
        return true;
    } else {
        return false;
    }
}

VideoType Series::getType() const{
    return series;
}

