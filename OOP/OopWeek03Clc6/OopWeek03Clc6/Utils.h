#pragma once

#include <vector>
#include <string>
using namespace std;

namespace Utils {
	class String {
	public:
		// Tokenizer
		static vector<std::string> split(string haystack, string needle) {
			vector<std::string> result;

			int startPos = 0;
			size_t foundPos = haystack.find(needle, startPos);

			while (foundPos != string::npos) {
				int count = foundPos - startPos;
				string token = haystack.substr(startPos, count);
				result.push_back(token);

				startPos = foundPos + needle.length();
				foundPos = haystack.find(needle, startPos);
			}

			// the remaining
			string token = haystack.substr(startPos, haystack.length() - startPos);
			result.push_back(token);

			return result;
		}
	};
}