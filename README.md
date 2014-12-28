linux
=====

## Git
```
git clone https://github.com/GeorgiCodes/linux.git
```

## Required Installs
```
yum upgrade
yum install kernel-devel
shutdown -r now
yum groupinstall 'Development Toolsa'
yum install git wget
```

## Mutt
```bash
yum install mutt
yum install cyrus-sasl-sql cyrus-sasl-plain cyrus-sasl-lib #sending doesn't seem to work without this
```

create `~\.muttrc` and put this
```bash
set from = username@gmail.com
set realname = "Georgi K"
set imap_user = username@gmail.com
set imap_pass = SECRET

# REMOTE GMAIL FOLDERS
set folder = "imaps://imap.gmail.com:993"
set spoolfile = "+INBOX"
set postponed ="+[Gmail]/Drafts"
#set trash = "+[Gmail]/Trash"
#set any_label = "+[Gmail]/any_label"
#set hostname = gmail.com

# LOCAL FOLDERS FOR CACHED HEADERS AND CERTIFICATES
set header_cache =~/.mutt/cache/headers
set message_cachedir =~/.mutt/cache/bodies
set certificate_file =~/.mutt/certificates

# SMTP SETTINGS
set smtp_url = "smtp://username@smtp.gmail.com:587"
set smtp_pass = SECRET # use the same passowrd as for IMAP

# SECURING
set move = no  #Stop asking to "move read messages to mbox"!
# Keep IMAP connection alive by polling intermittently (time in seconds).
set imap_keepalive = 300

# How often to check for new mail (time in seconds).
set mail_check = 120

##Sort by newest conversation first.
set sort = reverse-threads
set sort_aux = last-date-received

##Set editor to create new email
set editor='vi'

# set charset to utf-8
set send_charset="us-ascii:utf-8"
```

