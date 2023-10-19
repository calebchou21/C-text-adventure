#include <unistd.h>
#include "TextActions.h"
#include <ncurses.h>

int main() {
    char* text1 = "This is a test case\n";
    char* text2 = "This is a second test case!\n";
    char* text3 = "Ladies and gentlemen,We gather here today to remember and pay our respects to a remarkable individual, Tommy Turbulence Terry. Tommy's life was an embodiment of adventure and a testament to the human spirit's unwavering pursuit of the skies. His life, though tragically cut short, was a testament to his indomitable passion for flight and his unwavering commitment to the skies.Tommy's nickname, Turbulence, was not only a reflection of his prowess in the cockpit but also a symbol of his ability to navigate life's storms. He was a man of unyielding courage and a heart that knew no bounds. Tommy's love for aviation was evident to anyone who had the privilege of knowing him. From the very first moment he took to the skies, he was transformed, his spirit soaring alongside the aircraft he piloted.\n";
    char* text4 = "Bananas, often regarded as nature's portable snack, are a delightful fruit beloved for their sweet taste and convenient peel-and-eat design. With their vibrant yellow hue and distinct curved shape, bananas are not only appealing to the taste buds but also to the eye. This versatile fruit is a powerhouse of essential nutrients, boasting high levels of potassium, vitamin C, vitamin B6, and dietary fiber. Whether sliced atop morning cereals, blended into smoothies, or baked into luscious banana bread, bananas offer a burst of natural energy and a burst of tropical flavor. They play a vital role in many culinary delights, infusing desserts, salads, and savory dishes with their unique essence. Additionally, the sustainability of banana farming and its positive impact on communities worldwide make this humble fruit even more appealing. Overall, bananas stand as a testament to the beauty of simplicity and the joy that nature's creations bring to our lives.\n";
    screen_setup();
    /* type_options([text1, text2]); */
    type_text(text1, true, true);
    type_text(text2, false, true);
    char* options[] = {text1, text2};
    type_options(options, 2);
    screen_cleanup();
    return 0;
}

