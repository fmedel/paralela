FROM php:7.0.4-fpm

# install extensions
RUN apt-get update && apt-get install -y libmcrypt-dev libpq5 libpq-dev \
    && docker-php-ext-install mcrypt mbstring pgsql pdo_pgsql \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN apt-get update && apt-get install nano -y;
RUN apt-get update &&  apt-get install libpqxx-dev -y;
RUN apt-get update &&  apt-get install htop;
RUN apt-get update &&  apt-get install iputils-ping -y;
##RUN apt-get update &&  apt-get install libpng-dev -y; ## no funciona la libreria
##RUN apt-get update &&  apt-get install zlib1g-dev -y; ## no funciona libreira pasar la cosa antes
##RUN apt-get update &&  apt-get install libpng16-dev ; 
