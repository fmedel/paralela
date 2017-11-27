FROM php:7.0.4-fpm

# install extensions
RUN apt-get update && apt-get install -y libmcrypt-dev libpq5 libpq-dev \
    && docker-php-ext-install mcrypt mbstring pgsql pdo_pgsql \
&& apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
