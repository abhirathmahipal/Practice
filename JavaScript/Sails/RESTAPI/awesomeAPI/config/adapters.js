module.exports.adapters = {
    'default': 'disk',
    disk: {
        module: 'sails-disk'
    },

    'mysql-adapter': {
        adapter: 'sails-mysql',
        host: 'localhost',
        user: 'root',
        password: '',
        database: 'awesomeapi'
    }
};
