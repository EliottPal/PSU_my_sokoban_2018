int check_loose(char *buffer)
{
    int n = 0;
    int *pos = position_boxes(buffer);
    int total_boxes = number_boxes(buffer);
    int i = number_columns(buffer);
    int count = 0;

    while (count < total_boxes) {
        if (pos[count] - i == '#' && pos[count] + i == '#' && pos[count] - 1 == '#' || pos[count] + 1 == '#')
            n++;
        if (pos[count] - 1 == '#' && pos[count] - i == '#' || pos[count] + i == '#')
            n++;
        if (pos[count] + 1 == '#' && pos[count] - i == '#' || pos[count] + i == '#')
            n++;
        count++;
    }
}
