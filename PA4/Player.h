class Player {
	public:
	//Constructors and Destructors
		Player(int id, int x, int y);
		~Player();
		
	//Setters and Getters
		int getID() const;
		int getX() const;
		int getY() const;
		void setID(int newID);
		void setXY(int newX, int newY);

	private:
		int ID; //Player ID
		int x, y; //Player position
};