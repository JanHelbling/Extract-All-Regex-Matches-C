/* regexp.c regexp.h, extract RegexMatches in C

    Copyright (C) 2014 by Jan Helbling <jan.helbling@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    Extract all or a single regexmatch from a string. Take a look at example.c */

char *regexp (const char *string,const char *patrn, int *begin, int *end);
int RegExtractAll(const char *string, const char *pattern, char **buffer);
