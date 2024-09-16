#include "../inc/cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

// Function to extract a channel from a 32-bit color (ARGB)
int getChannel(int color, int shift) {
    return (color >> shift) & 0xFF;
}

// Function to combine channels into a 32-bit color (ARGB)
int combineChannels(int a, int r, int g, int b) {
    return (a << 24) | (r << 16) | (g << 8) | b;
}

// Function to blend two colors with a given alpha
int blendColors(int color1, int color2, float alpha) {
    // Extract channels from color1 (background)
    int r1 = getChannel(color1, 16); // Red channel
    int g1 = getChannel(color1, 8);  // Green channel
    int b1 = getChannel(color1, 0);  // Blue channel

    // Extract channels from color2 (foreground)
    int r2 = getChannel(color2, 16);
    int g2 = getChannel(color2, 8);
    int b2 = getChannel(color2, 0);

    // Perform alpha blending for each channel
    int r = (int)((alpha * r2) + ((1 - alpha) * r1));
    int g = (int)((alpha * g2) + ((1 - alpha) * g1));
    int b = (int)((alpha * b2) + ((1 - alpha) * b1));

    // Combine the new channels back into a single color (assuming full alpha = 255)
	// if (alpha > 0)
		// printf("----\n[%8X]\n[%8X]\n[%8X]\nAlpha [%f]\n", color1, color2, combineChannels(0, r, g, b), alpha);
    return combineChannels(0, r, g, b); // Full opacity in the result (alpha = 255)
}
