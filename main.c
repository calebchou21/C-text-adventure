#include <unistd.h>
#include "TextActions.h"
#include <ncurses.h>

int main() {
    char* text1 = "This is a test case\n";
    char* text2 = "This is a second test case!\n";
    char* text3 = "Bananas, often regarded as nature's portable snack, are a delightful fruit beloved for their sweet taste and convenient peel-and-eat design. With their vibrant yellow hue and distinct curved shape, bananas are not only appealing to the taste buds but also to the eye. This versatile fruit is a powerhouse of essential nutrients, boasting high levels of potassium, vitamin C, vitamin B6, and dietary fiber. Whether sliced atop morning cereals, blended into smoothies, or baked into luscious banana bread, bananas offer a burst of natural energy and a burst of tropical flavor. They play a vital role in many culinary delights, infusing desserts, salads, and savory dishes with their unique essence. Additionally, the sustainability of banana farming and its positive impact on communities worldwide make this humble fruit even more appealing. Overall, bananas stand as a testament to the beauty of simplicity and the joy that nature's creations bring to our lives.\n";
    screen_setup();
    type_text(text1);
    type_text(text2);
    type_text(text3);
    screen_cleanup();
    return 0;
}

