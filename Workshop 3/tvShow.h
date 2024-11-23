#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H

#include <vector>
#include "mediaItem.h"
#include "settings.h"
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <list>

namespace seneca {
	class TvShow;

	struct TvEpisode {
		const TvShow* m_show;
		unsigned short m_numberOverall;
		unsigned short m_season;
		unsigned short m_numberInSeason;
		std::string m_airDate;
		unsigned int m_length;
		std::string m_title;
		std::string m_summary;
	};

	class TvShow : public MediaItem {
		std::string m_id;
		std::vector<TvEpisode> m_episodes;

		TvShow(const std::string& id, const std::string& title, unsigned short year, const std::string& summary);

	public:
		void display(std::ostream& out) const override;
		static TvShow* createItem(const std::string& strShow);
		template<typename Collection_t> 
		static void addEpisode(Collection_t& col, const std::string& strEpisode);
		double getEpisodeAverageLength() const;
		std::list<std::string> getLongEpisodes() const;

		void displayLength() {
			for (auto& i : m_episodes) std::cout << i.m_title << "   " << i.m_length << std::endl;
		}
	};

	template<typename Collection_t>
	void TvShow::addEpisode(Collection_t& col, const std::string& strEpisode) {
		if (strEpisode.empty() || strEpisode[0] == '#') throw "Not a valid episode.";

		std::stringstream ss(strEpisode);
		std::string id, episodeStr, seasonStr, episodeInSeasonStr, airDate, lengthStr, title, summary;
		
		std::getline(ss, id, ',');
		std::getline(ss, episodeStr, ',');
		std::getline(ss, seasonStr, ',');
		std::getline(ss, episodeInSeasonStr, ',');
		std::getline(ss, airDate, ',');
		std::getline(ss, lengthStr, ',');
		std::getline(ss, title, ',');
		std::getline(ss, summary);

		MediaItem::trim(id);
		MediaItem::trim(episodeStr);
		MediaItem::trim(seasonStr);
		MediaItem::trim(episodeInSeasonStr);
		MediaItem::trim(airDate);
		MediaItem::trim(lengthStr);
		MediaItem::trim(title);
		MediaItem::trim(summary);

		unsigned short episode = static_cast<unsigned short>(std::stoi(episodeStr));
		unsigned short season = seasonStr.empty() ? 1 : static_cast<unsigned short>(std::stoi(seasonStr));
		unsigned short episodeInSeason = static_cast<unsigned short>(std::stoi(episodeInSeasonStr));
		unsigned int length = 0;

		std::stringstream timeStream(lengthStr);
		std::string hoursStr, minutesStr, secondsStr;
		std::getline(timeStream, hoursStr, ':');
		std::getline(timeStream, minutesStr, ':');
		std::getline(timeStream, secondsStr);

		unsigned int hours = hoursStr.empty() ? 0 : static_cast<unsigned int>(std::stoi(hoursStr));
		unsigned int minutes = minutesStr.empty() ? 0 : static_cast<unsigned int>(std::stoi(minutesStr));
		unsigned int seconds = secondsStr.empty() ? 0 : static_cast<unsigned int>(std::stoi(secondsStr));

		length = hours * 3600 + minutes * 60 + seconds;

		for (unsigned int i = 0; i < col.size(); ++i) {
			auto* tvShow = dynamic_cast<TvShow*>(col[i]);

			if (tvShow && tvShow->m_id == id) {
				tvShow->m_episodes.push_back({ tvShow, episode, season, episodeInSeason, airDate, length, title, summary });
				return;
			}
		}
		throw std::string("Show with ID [") + id + "] not found.";
	}
}

#endif