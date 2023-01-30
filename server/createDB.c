#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
    printf("%s\n", mysql_error(con));
    exit(1);
  }

  char *server = "127.0.0.1";
  char *user = "root";
  char *password = "Dung19102001";

  if (mysql_real_connect(con, server, user, password, NULL, 0, NULL, 0) == NULL)
  {
    printf("%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }
  if (!mysql_set_character_set(con, "utf8"))
  {
    printf("New client character set: %s\n",
           mysql_character_set_name(con));
  }

  //****CREATE DATABASE*****
  if (mysql_query(con, "CREATE DATABASE IF NOT EXISTS share_image CHARACTER SET utf8 COLLATE utf8_unicode_ci"))
  {
    if (strcmp(mysql_error(con),
               "Can't create database 'test'; database exists") == 0)
    {
      printf("Database is exists");
    }
    else
    {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
    }
  }
  printf("%s\n", "Create database succesfully ...");

  // ****SELECT DATABASE****
  if (mysql_query(con, "USE share_image"))
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }
  printf("%s\n", "Using database ...");

  // ****CREATE USER TABLE****
  if (mysql_query(con, "DROP TABLE IF EXISTS users"))
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }

  if (mysql_query(
          con,
          "CREATE TABLE users(id INT PRIMARY KEY AUTO_INCREMENT, username VARCHAR(255) UNIQUE, password VARCHAR(255),status VARCHAR(10))"))
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }
  printf("%s\n", "Create table users succesfully ...");

  // if (mysql_query(
  //         con,
  //         "CREATE TABLE using_accounts(id INT PRIMARY KEY AUTO_INCREMENT, username VARCHAR(255) UNIQUE)"))
  // {
  //   fprintf(stderr, "%s\n", mysql_error(con));
  //   mysql_close(con);
  //   exit(1);
  // }

  if (mysql_query(
          con,
          "INSERT INTO users(username, password,status) VALUES('admin', '123456','1'), ('dungdoan', '191001','0')"))
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }

  // mysql_close(con);
  // exit(0);
}
