using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Bll.Abstract;
using Dal.Abstract;
using entities.Concrete;

namespace Bll.concrete
{
    //yazara ait sırasıyla kurucu, ekleyici,silici,listeleyici,getirici,güncelleyici methodların tanımı
    public class YazarlarBll : IYazarlarBll
    {
        IYazarlarDal _yazarlar;
        public YazarlarBll(IYazarlarDal yazarlar)
        {
            _yazarlar = yazarlar;
        }
        public void Add(yazarlar yazarlar)
        {
            _yazarlar.Add(yazarlar);
        }

        public void Delete(yazarlar yazarlar)
        {
            _yazarlar.Delete(yazarlar);
        }

        public List<yazarlar> getAll()
        {
            return _yazarlar.getAll();
        }

        public yazarlar getOneById(int id)
        {
            return _yazarlar.getOne(x=>x.id==id);
        }

        public void Update(yazarlar yazarlar)
        {
            _yazarlar.Update(yazarlar);
        }
    }
}
