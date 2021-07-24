#include "mlx_extension.h"

int	mlx_get_hex_trgb(uint8_t t, uint8_t r, uint8_t g, uint8_t b)
{
	return ((t << 24) | (r << 16) | (g << 8) | (b));
}
