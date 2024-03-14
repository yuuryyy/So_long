/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:55:21 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/14 03:55:27 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct {
    int x;
    int y;
} p_coords;

void explore_paths(char **map, int map_height, int map_width, int x, int y, char target_char) {
    // Base case: Stop recursion if current position is out of bounds or not an open path
    if (x < 0 || x >= map_width || y < 0 || y >= map_height || map[y][x] != ' ') {
        return;
    }

    // Mark current position as target character
    map[y][x] = target_char;

    // Recursively explore neighboring cells
    explore_paths(map, map_height, map_width, x - 1, y, target_char); // Left
    explore_paths(map, map_height, map_width, x + 1, y, target_char); // Right
    explore_paths(map, map_height, map_width, x, y - 1, target_char); // Up
    explore_paths(map, map_height, map_width, x, y + 1, target_char); // Down
}

int main() {
    // Example map (5x5 grid)
    char *map[] = {
        "#####",
        "#   #",
        "#   #",
        "#   #",
        "#####"
    };

    int map_height = 5; // Number of rows
    int map_width = 5;  // Number of columns

    // Player coordinates
    p_coords player = {2, 2}; // Assuming player starts at (2, 2)

    // Target character to mark open paths
    char target_char = 'x';

    // Call function to explore paths from player's position
    explore_paths(map, map_height, map_width, player.x, player.y, target_char);

    // Output updated map
    for (int i = 0; i < map_height; i++) {
        printf("%s\n", map[i]);
    }

    return 0;
}