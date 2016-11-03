BEGIN TRANSACTION;
CREATE TABLE "customer" (
	`name`	VARCHAR(50) PRIMARY KEY UNIQUE,
	`street`	VARCHAR(75) NOT NULL,
	`city`	VARCHAR(50) NOT NULL,
	`state`	VARCHAR(2) NOT NULL,
	`zip`	INTEGER NOT NULL,
	`interest`	VARCHAR(50) NOT NULL DEFAULT 'somewhat interested',
	`status`	VARCHAR(50) NOT NULL DEFAULT 'nice to have',
	`testimonial`	VARCHAR(300),
	`requested`	VARCHAR(50) NOT NULL DEFAULT 'not requested',
	`isActive` INTEGER NOT NULL DEFAULT 1
);
CREATE TABLE "user" (
	`name` VARCHAR(50) PRIMARY KEY UNIQUE,
	`password` VARCHAR(10) UNIQUE
);
COMMIT;
