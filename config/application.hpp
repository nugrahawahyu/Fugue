Application* application = new Application(
    /** Controller yang digunakan harus merupakan anak class BaseController. */
    new Controller(),

    /** Board yang digunakan harus merupakan anak class Board. */
    new Board(),

    /** Serial Baud Rate */
    115200,

    /** Start serial communication? */
    true
);