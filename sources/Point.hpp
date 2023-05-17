namespace ariel {
    class Point {
        public:
            Point(double x, double y);
            double distance(Point other);
            void print();
            Point MoveTowards(Point src, Point dest, double dist);
        private:
            double x;
            double y;
        
    };    
}