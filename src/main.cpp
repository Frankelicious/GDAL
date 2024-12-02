#include <iostream>
#include <proj.h>

int main() {
    // Initialize a PROJ context
    PJ_CONTEXT *context = proj_context_create();

    if (!context) {
        std::cerr << "Failed to create PROJ context." << std::endl;
        return 1;
    }

    // Create a transformation from WGS84 (EPSG:4326) to Web Mercator (EPSG:3857)
    PJ *transformation = proj_create_crs_to_crs(context, "EPSG:4326", "EPSG:3857", nullptr);

    if (!transformation) {
        std::cerr << "Failed to create PROJ transformation." << std::endl;
        proj_context_destroy(context);
        return 1;
    }

    // Prepare a coordinate to transform (latitude, longitude -> y, x)
    PJ_COORD input = proj_coord(12.4924, 41.8902, 0, 0); // Example: Rome, Colosseum
    PJ_COORD output = proj_trans(transformation, PJ_FWD, input);

    // Output the transformed coordinates
    std::cout << "Input coordinates (longitude, latitude): "
              << input.xy.x << ", " << input.xy.y << std::endl;

    std::cout << "Transformed coordinates (x, y in meters): "
              << output.xy.x << ", " << output.xy.y << std::endl;

    // Clean up
    proj_destroy(transformation);
    proj_context_destroy(context);

    return 0;
}
