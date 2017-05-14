module.exports = function alreadyInUse (err) {
  var res = this.res;

  if (err.invalidAttributes.email) {
    return res.send(409, 'Email address is already taken by another user');
  }

  if (err.invalidAttributes.username)
    return res.send(409, 'Username is already taken by another use');

  return res.send(500);
}
