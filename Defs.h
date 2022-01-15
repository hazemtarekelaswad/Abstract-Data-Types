#pragma once

// Enums for hash table implementation

enum class Status { 
	EMPTY, 
	OCCUPIED, 
	REMOVED 
};

enum class Probing {
	LINEAR = 1,
	QUADRATIC = 2,
};
