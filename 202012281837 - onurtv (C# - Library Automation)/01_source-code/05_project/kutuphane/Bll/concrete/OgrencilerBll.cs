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
    //öğrenci ait sırasıyla kurucu, ekleyici,silici,listeleyici,getirici,güncelleyici methodların tanımı
    public class OgrencilerBll: IOgrencilerBll
    {
        IOgrencilerDal _Ogrenciler;
        public OgrencilerBll(IOgrencilerDal Ogrenciler)
        {
            _Ogrenciler = Ogrenciler;
        }
        public void Add(ogrenciler ogrenciler)
        {
            _Ogrenciler.Add(ogrenciler);
        }

        public void Delete(ogrenciler ogrenciler)
        {
            _Ogrenciler.Delete(ogrenciler);
        }

        public List<ogrenciler> getAll()
        {
            return _Ogrenciler.getAll(x=>x.durum==true);
        }

        public ogrenciler getOneById(int id)
        {
            return _Ogrenciler.getOne(x => x.id == id);
        }

        public void Update(ogrenciler ogrenciler)
        {
            _Ogrenciler.Update(ogrenciler);
        }
    }
}
