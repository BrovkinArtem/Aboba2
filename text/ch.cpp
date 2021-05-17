
#include <string>
#include "_text.h"

void ch(text txt)
{
    auto cursor_line = txt->cursor->line;
    int cursor_pos = txt->cursor->position;
    int line_len = (*cursor_line).size();
    int begin_len = line_len-cursor_pos;
    std::string new_line;
    new_line =
	(*cursor_line).substr(cursor_pos,begin_len) + (*cursor_line).substr(0,cursor_pos);
    (*cursor_line) = new_line;
}
